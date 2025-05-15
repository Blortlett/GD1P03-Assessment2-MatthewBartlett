/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cCharacter]
Description : [cCharacter is a base class only inherited by cPlayerCharacter. This class contains physics and other player movement variables and functions]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cCharacter.h"

cCharacter::cCharacter(
	eCharacterType type,
	sf::Vector2f position,
	sf::FloatRect bounds,
	sf::Vector2f colliderOffset,
	sf::Vector2f _maxVelocity
) : mDebugColliderShape(bounds.size)
, mDebugPositionShape(4)
, mCharacterType(type)
, mCollider(bounds)
{
	mDebugColliderShape.setOrigin(bounds.size / 2.0f);
	mDebugPositionShape.setOrigin(sf::Vector2f(2, 2));
	mColliderOffset = colliderOffset;
}

cCharacter::~cCharacter()
{
}

void cCharacter::CharacterPhysicsUpdate(float _DeltaSeconds)
{
	// Add Gravity to Velocity
	mVelocity.y += mGravity * _DeltaSeconds;
	// Add velocity to collider position
	mCollider.mBounds.position += mVelocity * _DeltaSeconds; // movement

	// Clamp position to not fall below ground && grounded reset
	// Deleteable - just stops player fall thru ground
	if (mCollider.mBounds.position.y > 750)
	{
		mPlayerAnimator.EndFall();
		mCollider.mBounds.position.y = 750;
		mVelocity.y = 0;
		mIsGrounded = true;
	}

	// Clamp velocity to max velocities
	if (mVelocity.x > mMaxVelocity.x) { mVelocity.x = mMaxVelocity.x; }
	if (mVelocity.x < (-1 * mMaxVelocity.x)) { mVelocity.x = (-1 * mMaxVelocity.x); }
	if (mVelocity.y < (-1 * mMaxVelocity.y)) { mVelocity.y = (-1 * mMaxVelocity.y); }
	if (mIsWallsliding) // Wallslide falling
	{
		if (mVelocity.y > mMaxWallslideFallVelocity) { mVelocity.y = mMaxWallslideFallVelocity; }
	}
	else if (mVelocity.y > mMaxVelocity.y) // Falling
	{
		mVelocity.y = mMaxVelocity.y;
	}

	mPosition = mCollider.mBounds.position - mColliderOffset;
}


void cCharacter::DrawDebug(sf::RenderWindow& renderWindow)
{
	if (!cApplicationManager::GetInstance().IsDebugModeActive()) return;
	mDebugColliderShape.setPosition(mCollider.mBounds.position);
	mDebugPositionShape.setPosition(mPosition);
	renderWindow.draw(mDebugColliderShape); // draw collider
	renderWindow.draw(mDebugPositionShape); // draw player ground center
}

void cCharacter::OnCollision(sf::Vector2f direction)
{ // Handle collision differently depending on direction
	if (direction.x < 0.0f)
	{
		// Collision on the right
		if (!mIsWallsliding)
			mVelocity.x = .4f;
		SetWallsliding();
	}
	else if (direction.x > 0.0f)
	{
		// Collision on the left
		if (!mIsWallsliding)
			mVelocity.x = -.4f;
		SetWallsliding();
	}
	if (direction.y < 0.0f)
	{
		// Collision on the bottom
		mVelocity.y = 2.f;
		if (!mIsGrounded)
			cAudioPlayer::GetInstance().SFXPlayLandFall();
		mIsGrounded = true;
		mPlayerAnimator.EndFall();
	}
	if (direction.y > 0.0f)
	{
		// Collision on the top
		mVelocity.y = 0.0f;
	}
}

void cCharacter::OnPhysicsCollision(sf::Vector2f direction, sf::Vector2f& velocityTransfer)
{
	// Handle collision differently depending on direction
	if (direction.x < 0.0f)
	{
		// Collision on the right
		
		velocityTransfer.x = mVelocity.x;
		mVelocity.x *= .5f;
		SetWallsliding();
	}
	else if (direction.x > 0.0f)
	{
		// Collision on the left
		velocityTransfer.x = mVelocity.x;
		mVelocity.x *= .5f;
		SetWallsliding();
	}
	if (direction.y < 0.0f)
	{
		// Collision on the bottom
		mVelocity.y -= velocityTransfer.y * .004f;
		velocityTransfer.y = mVelocity.y;
		//if (!mIsGrounded)
			//cAudioPlayer::GetInstance().SFXPlayLandFall();
		mIsGrounded = true;
		mPlayerAnimator.EndFall();
	}
	if (direction.y > 0.0f)
	{
		// Collision on the top
		velocityTransfer.y = mVelocity.y;
	}
}

void cCharacter::MovePlayerCharacterPosition(sf::Vector2f position)
{
	mPosition = position;
	mCollider.MoveColliderPosition(position + mColliderOffset);
}

void cCharacter::KillVelocity()
{
	mVelocity = sf::Vector2f(0, 0);
}

void cCharacter::SetWallsliding()
{
	if (!mIsGrounded)
	{
		if (!mIsTouchingWall)
			//cAudioPlayer::GetInstance().SFXPlayLandFall();
		mIsTouchingWall = true;
		if (mVelocity.y > 0)
		{
			// Wallsliding - Downward momentum
			mPlayerAnimator.SetWallsliding(true);
			mIsWallsliding = true;
		}
	}
}
