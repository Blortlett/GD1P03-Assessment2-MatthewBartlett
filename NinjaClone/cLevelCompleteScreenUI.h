#pragma once
#include "cApplicationManager.h"
#include "cNextLevelButtonUI.h"
#include "cLevelPlatformsList.h"
#include "cFileInterface.h"

class cLevelCompleteScreenUI
{
private:
	sf::RenderWindow& mRenderWindow;
	sf::Text mLevelCompleteText;
	cNextLevelButtonUI mNextLevelButton;

	bool mIsActive = false;

public:
	cLevelCompleteScreenUI(sf::RenderWindow& renderWindow, cLevelPlatformsList& levelPlatformList, cFileInterface& fileInterface);
	~cLevelCompleteScreenUI();

	void Update();
};