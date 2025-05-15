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
#include "cLoadButton.h"

cLoadButton::cLoadButton(sf::Vector2f position, sf::Vector2f size, cFileInterface& _userFileInterface, cLevelPlatformsList& platformList)
	: cButtonUI(position, size)
	, mFileInterface(_userFileInterface)
	, mPlatformList(platformList)
	, mUIIcon(cApplicationManager::GetInstance().mLoadIcon)
{
	// Set position
	mUIIcon.setOrigin(mUIIcon.getLocalBounds().size / 2.0f);
	mUIIcon.setPosition(position);
}

cLoadButton::~cLoadButton()
{
}

void cLoadButton::OnButtonClick()
{
	// Load to the platform list
	mFileInterface.LoadLevelDialog();
}

void cLoadButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Update(window);
	// Draw Button to screen
	cButtonUI::Draw(window);
	window.draw(mUIIcon);
}