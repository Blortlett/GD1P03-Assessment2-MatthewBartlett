#pragma once
#include "cGameObject.h"
#include "cAnimator.h"
#include "cBoxCollider.h"
#include "cApplicationManager.h"

enum eCharacterType {
	TYPE_BLANK,
	TYPE_PLAYER,
	TYPE_ENEMY,
	TYPE_FRIEND,
	TYPE_NEUTRAL
};

class cCharacter
{
protected:
	eCharacterType mCharacterType;
	// Character Animator
	cAnimator mPlayerAnimator;
	// Physics members
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;
	sf::Vector2f mMaxVelocity;
	float mMaxWallslideFallVelocity = 40;
	float mGravity = 300;
	// Character members
	bool mIsFacingRight = true;
	// Dampen Movment
	float mMoveInputMultGrounded = 250.0f; // .8 without delta time
	float mMoveInputMultAirborne = 150.0f; // .3 without delta time
	float mVelocityDampGrounded = 3;
	float mVelocityDampAirborne = .5;
	float mVelocityDeadzone = 15;
	// Collision
	cBoxCollider mCollider;
	sf::Vector2f mColliderOffset;
	// Character Jumping
	bool mIsGrounded = false;
	bool mIsTouchingWall = false;
	bool mIsWallsliding = false;
	float mJumpImpulse = 100;
	sf::Vector2f mWallslideJumpImpulse;
	// Debug
	sf::RectangleShape mDebugColliderShape;
	sf::CircleShape mDebugPositionShape;

	void SetWallsliding();
public:
	cCharacter(
		eCharacterType type,
		sf::Vector2f position,
		sf::FloatRect bounds,
		sf::Vector2f colliderOffset,
		sf::Vector2f _maxVelocity
	);
	~cCharacter();

	void CharacterPhysicsUpdate(float _DeltaSeconds);
	void DrawDebug(sf::RenderWindow& renderWindow);
	bool IsGrounded() const { return mIsGrounded; }
	void OnCollision(sf::Vector2f direction);

	void MovePlayerCharacterPosition(sf::Vector2f position);
	void KillVelocity();


	// Collision
	cBoxCollider& GetCollider() { return mCollider; }
};