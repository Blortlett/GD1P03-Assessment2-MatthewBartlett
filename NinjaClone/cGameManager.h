/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cGameManager]
Description : [This class handles game tick and calls update methods]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayerCharacter.h"
#include "cLevelPlatformsList.h"
#include "cFileInterface.h"
#include "cPlayerInput.h"
#include <iostream>

class cLevelCompleteScreenUI;

class cGameManager
{
public:
	cGameManager(sf::RenderWindow& window, cPlayerInput& playerInput, cLevelPlatformsList& platformsList, cFileInterface& fileInterface);
	~cGameManager();
	// GameTick types
	void GameTick();
	void DrawOnlyTick();
	void DrawDeathTick();
	// System only inputs
	void HandleSystemInputs();
	// Respawn Player
	void RespawnPlayer();

private:
	// Clock & DeltaTime
	sf::Clock mClock;
	sf::Time mDeltaTime;
	float mDeltaSeconds;
	void RefreshDeltaTime();
	// Death screen timer variables
	float mDeathScreenTimer = 0;
	float mDeathFlashTimer = 0;
	float mDeathScreenTimeMax = 3; // Death screen timer
	float mDeathFlashTimeMax = .4; // alternate flashing timer
	bool mDrawCharacterOnDeath = true;

	// InputVariables
	bool mPauseKeyHeld = false;
	bool mDebugKeyHeld = false;

	// Render Window
	sf::RenderWindow& mGameWindow;

	// Player Character
	cPlayerInput& mPlayerInput;
	cPlayerCharacter mPlayerCharacter;

	// Platforms
	cLevelPlatformsList& mPlatformsList;

	// UI
	cLevelCompleteScreenUI* mLevelCompleteUI;
};