/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevelCompleteScreenUI]
Description : [cLevelCompleteScreenUI encapsulates the level win UI to be displayed on level complete]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cApplicationManager.h"
#include "cNextLevelButtonUI.h"
#include "cLevelPlatformsList.h"
#include "cFileInterface.h"
#include "cGameManager.h"

class cLevelCompleteScreenUI
{
private:
	sf::RenderWindow& mRenderWindow;
	sf::Text mLevelCompleteText;
	cNextLevelButtonUI mNextLevelButton;

	bool mIsActive = false;

public:
	cLevelCompleteScreenUI(sf::RenderWindow& renderWindow, cLevelPlatformsList& levelPlatformList, cFileInterface& fileInterface, cGameManager& gameManager);
	~cLevelCompleteScreenUI();

	void Update();
};