/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLoadButton]
Description : [cLoadButton when instantiated allows the player to click a button to load a level in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cApplicationManager.h"
#include "cButtonUI.h"
#include "cFileInterface.h"
#include "cLevelPlatformsList.h"

class cLoadButton : public cButtonUI
{
public:
	cLoadButton(sf::Vector2f position, sf::Vector2f size, cFileInterface& _userFileInterface, cLevelPlatformsList& platformList);
	~cLoadButton();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;

private:
	cFileInterface& mFileInterface;
	cLevelPlatformsList& mPlatformList;

	sf::Sprite mUIIcon;
};