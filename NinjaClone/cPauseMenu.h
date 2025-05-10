#pragma once
#include "cApplicationManager.h"
#include "cLevelPlatformsList.h"
#include "cResumeButton.h"
#include "cReturnToMainMenu.h"

class cPauseMenu
{
private:
	// Menu stuff
	sf::RenderWindow& mWindow;
	sf::Text mMenuTitleText;
	sf::RectangleShape mMenuBackground;
	// Menu Buttons
	cResumeButton mResumeButton;
	cReturnToMainMenu mMainMenuButton;

public:
	cPauseMenu(sf::RenderWindow& window, cLevelPlatformsList& platformList);
	~cPauseMenu();

	bool mIsActive = false;
	void Update();
};