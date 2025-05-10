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
	// Gamestate vars
	bool mIsLevelEditorRunning = false;
	bool mIsGameRunning = false;
	bool mIsMainMenuActive = true;
	bool mIsDoorUnlocked = false;
	bool mIsLevelComplete = false;
	// Sprites - I should have done this for all sprites
	sf::Texture mLevelExitOpenTex;
	sf::Texture mLevelExitClosedTex;
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

	// Getters
	bool IsLevelEditorRunning() { return mIsLevelEditorRunning; }
	bool IsGameRunning() { return mIsGameRunning; }
	bool IsMainMenuActive() { return mIsMainMenuActive; }
	bool IsDoorUnlocked() { return mIsDoorUnlocked;  }
	bool IsLevelComplete() { return mIsLevelComplete;  }

	sf::Font& GetFont() { return mGameFont; }
	// Setters
	void SetLevelEditorRunning(bool isRunning) { mIsLevelEditorRunning = isRunning; }
	void SetGameRunning(bool isRunning) { mIsGameRunning = isRunning; }
	void SetMainMenuActive(bool isActive) { mIsMainMenuActive = isActive; }
	void SetIsDoorUnlocked(bool isDoorUnlocked) { mIsDoorUnlocked = isDoorUnlocked;  }
	void SetIsLevelComplete(bool isLevelComplete) { mIsLevelComplete = isLevelComplete;  }

	sf::Sprite* mLevelExitOpenSprite;
	sf::Sprite* mLevelExitClosedSprite;
};