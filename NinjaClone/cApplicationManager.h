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

	// Gamestate global vars			// I hear this is a bad idea? Antipattern?
	bool mIsLevelEditorRunning = false;
	bool mIsGameRunning = false;
	bool mIsGamePaused = false;
	bool mIsMainMenuActive = true;
	bool mIsDoorUnlocked = false;
	bool mIsLevelComplete = false;
	bool mIsDebugModeActive = false;

	// Textures - I should have done this for all Textures to load sprites from here
	sf::Texture mLevelExitOpenTex;
	sf::Texture mLevelExitClosedTex;
	// Enemy sprites
	sf::Texture* mMineTexture;
	sf::Texture* mMushroomManTexture;

	// Font
	sf::Font mGameFont;

	// Level names
	const std::string mLevelNames[5] = { "Level1", "Level2", "Level3", "Level4", "Level5" };
	int mLevelCount = 0;
public:
	// Get the single instance of the class
	static cApplicationManager& GetInstance()
	{
		static cApplicationManager instance; // Static instance created on first call
		return instance;
	}

	// Level Loading
	const std::string GetNextLevelName();
	void ResetGameplayVariables();

	// Get EnemyTextures
	sf::Texture& GetMineTexture() { return *mMineTexture; }
	sf::Texture& GetMushroomTexture() { return *mMushroomManTexture; }

	// Gamestate Getters
	bool IsLevelEditorRunning() { return mIsLevelEditorRunning; }
	bool IsGameRunning() { return mIsGameRunning; }
	bool IsGamePaused() { return mIsGamePaused; }
	bool IsMainMenuActive() { return mIsMainMenuActive; }
	bool IsDoorUnlocked() { return mIsDoorUnlocked;  }
	bool IsLevelComplete() { return mIsLevelComplete;  }
	bool IsDebugModeActive() { return mIsDebugModeActive;  }

	sf::Font& GetFont() { return mGameFont; }
	// Setters
	void SetLevelEditorRunning(bool isRunning) { mIsLevelEditorRunning = isRunning; }
	void SetGameRunning(bool isRunning) { mIsGameRunning = isRunning; }
	void SetGamePaused(bool isPaused) { mIsGamePaused = isPaused; }
	void SetMainMenuActive(bool isActive) { mIsMainMenuActive = isActive; }
	void SetIsDoorUnlocked(bool isDoorUnlocked) { mIsDoorUnlocked = isDoorUnlocked;  }
	void SetIsLevelComplete(bool isLevelComplete) { mIsLevelComplete = isLevelComplete;  }
	void SetIsDebugModeActive(bool isDebugModeActive) { mIsDebugModeActive = isDebugModeActive;  }

	// Reset level count
	void ResetLevelProgress();

	sf::Sprite* mLevelExitOpenSprite;
	sf::Sprite* mLevelExitClosedSprite;
};