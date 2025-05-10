#pragma once
#include <SFML/Graphics.hpp>
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
public:
	// Get the single instance of the class
	static cApplicationManager& GetInstance()
	{
		static cApplicationManager instance; // Static instance created on first call
		return instance;
	}

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