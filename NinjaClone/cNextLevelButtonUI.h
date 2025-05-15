/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cNextLevelButtonUI]
Description : [cNextLevelButtonUI provides a button for the player to push to continue to the next level after completing a level]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"
#include "cLevelPlatformsList.h"
#include "cFileInterface.h"
#include "cAudioPlayer.h"
class cGameManager;

class cNextLevelButtonUI : public cButtonUI
{
private:
	sf::Text mButtonText;

	cLevelPlatformsList& mLevelPlatformList;
	cFileInterface& mFileInterface;
	cGameManager& mGameManager;

public:
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;

	cNextLevelButtonUI(cLevelPlatformsList& platformList, cFileInterface& fileInterface, cGameManager& gameManager);
	~cNextLevelButtonUI();
};