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
#include "cLevelCompleteScreenUI.h"

cLevelCompleteScreenUI::cLevelCompleteScreenUI(sf::RenderWindow& renderWindow, cLevelPlatformsList& levelPlatformList, cFileInterface& fileInterface, cGameManager& gameManager)
	: mLevelCompleteText(cApplicationManager::GetInstance().GetFont(), "Level Complete!", 20U)
	, mRenderWindow(renderWindow)
	, mNextLevelButton(levelPlatformList, fileInterface, gameManager)
{
	mLevelCompleteText.setFillColor(sf::Color::Black);
	mLevelCompleteText.setCharacterSize(62);
	mLevelCompleteText.setPosition(sf::Vector2f(renderWindow.getSize() / 2U));
	mLevelCompleteText.setOrigin(mLevelCompleteText.getGlobalBounds().size / 2.0f);
}

cLevelCompleteScreenUI::~cLevelCompleteScreenUI()
{

}

void cLevelCompleteScreenUI::Update()
{
	if (cApplicationManager::GetInstance().IsLevelComplete())
	{
		mRenderWindow.draw(mLevelCompleteText);
		mNextLevelButton.Update(mRenderWindow);
		mNextLevelButton.Draw(mRenderWindow);
	}
}
