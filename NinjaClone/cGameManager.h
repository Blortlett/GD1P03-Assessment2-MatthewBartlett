#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayerCharacter.h"
#include "cLevelPlatformsList.h"
#include "cLevelCompleteScreenUI.h"
#include "cFileInterface.h"
#include "cPlayerInput.h"
#include <iostream>

class cGameManager
{
public:
	cGameManager(sf::RenderWindow& window, cPlayerInput& playerInput, cLevelPlatformsList& platformsList, cFileInterface& fileInterface);
	~cGameManager();
	// GameTick types
	void GameTick();
	void DrawOnlyTick();
	// System only inputs
	void HandleSystemInputs();

private:
	// Clock & DeltaTime
	sf::Clock mClock;
	sf::Time mDeltaTime;
	float mDeltaSeconds;
	void RefreshDeltaTime();

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
	cLevelCompleteScreenUI mLevelCompleteUI;
};