/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cSaveButton]
Description : [cSaveButton when instantiated allows the player to click a button to save a level in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cButtonUI.h"
#include "cFileInterface.h"
#include "cLevelPlatformsList.h"

class cSaveButton : public cButtonUI
{
public:
	cSaveButton(sf::Vector2f position, sf::Vector2f size, cFileInterface& _userFileInterface, cLevelPlatformsList& platformList);
	~cSaveButton();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;

private:
	cFileInterface& mFileInterface;
	cLevelPlatformsList& mPlatformList;

	sf::Texture mSaveIconTexture; // Load Texture
	sf::Sprite mUIIcon; // create sprite from above
};