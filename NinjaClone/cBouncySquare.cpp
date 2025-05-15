/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBouncySquare]
Description : [This class provides a bouncy platform the player jump on to get a jump boost and launch high in the air]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cBouncySquare.h"

cBouncySquare::cBouncySquare(sf::Vector2f position)
	: mCollider(sf::FloatRect(position, mSize))
	, mPosition(position)
	, mDebugWidget(mCollider)
{
	mRectShape.setPosition(position);
	mRectShape.setSize(mSize);
	mRectShape.setOrigin(mSize / 2.f);

	mRectShape.setFillColor(sf::Color::Black);
	mRectShape.setOutlineColor(sf::Color::White);
	mRectShape.setOutlineThickness(2);
}

cBouncySquare::~cBouncySquare()
{
}

bool cBouncySquare::CheckCollideWithPlayer(cPlayerCharacter& playerCharacter)  // got rid of cPlatformList's mCollisionDirection
{
	sf::Vector2f vfCollisionDirection;
	sf::Vector2f vfCollisionVelocity = mVelocity;
	// Check platform collision with player
	if (mCollider.CheckCollision(playerCharacter.GetCollider(), vfCollisionDirection, 1.f))
	{
		// If collision, tell player object:
		playerCharacter.OnPhysicsCollision(vfCollisionDirection, vfCollisionVelocity);
		mVelocity = vfCollisionVelocity;
		return true;
	}
	return false;
}

bool cBouncySquare::CheckCollideWithPoint(sf::Vector2f point)
{ // Delete helper code
	sf::Vector2f newPoint = point;
	newPoint += mCollider.GetHalfSize();
	return mCollider.CheckCollisionPoint(newPoint);
}

void cBouncySquare::Update(float _DeltaSeconds)
{
	// Add fricition
	mVelocity = mVelocity * .999f;

	mVelocity = (mVelocity - ((mCollider.GetPosition() - mPosition) * _DeltaSeconds) * 1000.f);
	// Update position based on current velocity
    mCollider.MoveColliderPosition(mCollider.GetPosition() + (mVelocity * _DeltaSeconds));
    // Sync the visual shape with the collider's position
	mRectShape.setPosition(mCollider.GetPosition());
}

void cBouncySquare::Draw(sf::RenderWindow& window)
{
	window.draw(mRectShape);
	if (cApplicationManager::GetInstance().IsDebugModeActive())
	{
		mDebugWidget.DrawWidget(window);
	}
}

sf::Vector2f cBouncySquare::GetPosition()
{
	return mPosition;
}
