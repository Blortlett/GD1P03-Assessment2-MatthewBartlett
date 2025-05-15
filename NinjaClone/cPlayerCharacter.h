/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerCharacter]
Description : [cPlayerCharacter inherits from cCharacter. This class is responsible for input handling and giving the player a character to control to play thru the game]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlayerInput.h"
#include "cCharacter.h"
#include "cApplicationManager.h"
#include "cAudioPlayer.h"

class cPlayerCharacter : public cCharacter
{
public:
	cPlayerCharacter(sf::Vector2f _position, cPlayerInput& playerInput);
	~cPlayerCharacter();
	void Update(float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow);
	void SetUngrounded(); // Called from cLevelPlatformList.cpp
	void KillInput();



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

	float normalize(float value) {
		return (value > 0) ? 1 : (value < 0) ? -1 : 0;
	}
};