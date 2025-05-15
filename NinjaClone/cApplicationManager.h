/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cApplicationManager]
Description : [This singleton class handles global variables and loads in textures for other classes - mostly UI stuff]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


class cApplicationManager
{
private:
	// Private constructor/destructor to prevent non singleton use
	cApplicationManager();
	~cApplicationManager();

	// Gamestate global vars			// I hear this is a bad idea? Lol this whole game is an antipattern
	bool mIsLevelEditorRunning = false;
	bool mIsGameRunning = false;
	bool mIsGamePaused = false;
	bool mIsMainMenuActive = true;
	bool mIsDoorUnlocked = false;
	bool mIsLevelComplete = false;
	bool mIsDebugModeActive = false;
	bool mIsPlayerDead = false;


	// Textures - I should have done this for all Textures to load sprites from here
	sf::Texture mLevelExitOpenTex;
	sf::Texture mLevelExitClosedTex;
	// Enemy textures
	sf::Texture mMineTexture;
	sf::Texture mMushroomManTexture;
	// UI icons
	sf::Texture mLoadIconTexture;
	sf::Texture mSaveIconTexture;
	sf::Texture mKeyIconTexture;

	// Font
	sf::Font mGameFont;

	// Level names
	const std::string mLevelNames[9] = { "Level1" , "Level2", "Level3", "Level4", "Level5", "Level6", "Level7", "Level8", "Level9" };
	const int mMaxLevel = 9;	//////// mLevelNames.Size() wants to fuck me around

	int mLevelCount = 0;

public:
	// Get the single instance of the class
	static cApplicationManager& GetInstance()
	{
		static cApplicationManager instance; // Static instance created on first call
		return instance;
	}

	// Level Loading
	const std::string GetCurrentLevelName();
	const std::string GetNextLevelName();
	void ResetGameplayVariables();

	// Gamestate Getters
	bool IsLevelEditorRunning() { return mIsLevelEditorRunning; }
	bool IsGameRunning() { return mIsGameRunning; }
	bool IsGamePaused() { return mIsGamePaused; }
	bool IsMainMenuActive() { return mIsMainMenuActive; }
	bool IsDoorUnlocked() { return mIsDoorUnlocked;  }
	bool IsLevelComplete() { return mIsLevelComplete;  }
	bool IsDebugModeActive() { return mIsDebugModeActive;  }
	bool IsPlayerDead() { return mIsPlayerDead;  }

	sf::Font& GetFont() { return mGameFont; }
	// Setters
	void SetLevelEditorRunning(bool isRunning) { mIsLevelEditorRunning = isRunning; }
	void SetGameRunning(bool isRunning) { mIsGameRunning = isRunning; }
	void SetGamePaused(bool isPaused) { mIsGamePaused = isPaused; }
	void SetMainMenuActive(bool isActive) { mIsMainMenuActive = isActive; }
	void SetIsDoorUnlocked(bool isDoorUnlocked) { mIsDoorUnlocked = isDoorUnlocked;  }
	void SetIsLevelComplete(bool isLevelComplete) { mIsLevelComplete = isLevelComplete;  }
	void SetIsDebugModeActive(bool isDebugModeActive) { mIsDebugModeActive = isDebugModeActive;  }
	void SetIsPlayerDead(bool isPlayerDead) { mIsPlayerDead = isPlayerDead;  }

	// Reset level count
	void ResetLevelProgress();

	// door sprites
	sf::Sprite* mLevelExitOpenSprite;
	sf::Sprite* mLevelExitClosedSprite;

	// enemy sprites
	sf::Sprite mEnemyMineSprite;
	sf::Sprite mEnemyMushroomSprite;

	//UIicons
	sf::Sprite mLoadIcon;
	sf::Sprite mSaveIcon;
	sf::Sprite mKeyIcon;


	// Game won variables
	bool mIsGameComplete = false;
	bool IsGameWon();
};