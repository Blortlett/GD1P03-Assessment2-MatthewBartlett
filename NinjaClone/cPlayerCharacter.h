#pragma once
#include "cPlayerInput.h"
#include "cCharacter.h"
#include "cApplicationManager.h"

class cPlayerCharacter : public cCharacter
{
public:
	cPlayerCharacter(sf::Vector2f _position, cPlayerInput& playerInput);
	~cPlayerCharacter();
	void Update(float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow);
	void SetUngrounded(); // Called from cLevelPlatformList.cpp



	// Player Values
	static const sf::Vector2f PLAYER_SIZE;
	static const sf::FloatRect PLAYER_BOUNDS;
	static const sf::Vector2f PLAYER_MAX_VELOCITY;
	static const sf::Vector2f PLAYER_COLLIDER_OFFSET;
private:
	void Jump();
	void JumpWallsliding();
	void HandleInput();
	// Player Input
	cPlayerInput& mPlayerInput;
	sf::Vector2f m_vPlayerInputNormalized;
	bool mJumpKeyHeld = false;
};