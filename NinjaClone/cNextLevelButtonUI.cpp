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
#include "cNextLevelButtonUI.h"
#include "cGameManager.h"


void cNextLevelButtonUI::OnButtonClick()
{
	// Reset game variables and load new level
	mLevelPlatformList.ClearList();
	cApplicationManager::GetInstance().ResetGameplayVariables();
	mFileInterface.LoadLevelByName(cApplicationManager::GetInstance().GetNextLevelName());
	mGameManager.RespawnPlayer();
	cAudioPlayer::GetInstance().PlayLevelMusic();
}

void cNextLevelButtonUI::Draw(sf::RenderWindow& window)
{
	window.draw(mButtonShape);
	window.draw(mButtonText);
}

cNextLevelButtonUI::cNextLevelButtonUI(cLevelPlatformsList& platformList, cFileInterface& fileInterface, cGameManager& gameManager)
	: cButtonUI(sf::Vector2f(1366 / 2, (768 / 2) + 150), sf::Vector2f(300, 100))
	, mButtonText(cApplicationManager::GetInstance().GetFont(), "Next Level", 50U)
	, mLevelPlatformList(platformList)
	, mFileInterface(fileInterface)
	, mGameManager(gameManager)
{
	// Center text
	mButtonText.setPosition(mPosition);
	mButtonText.setCharacterSize(20);
	mButtonText.setOrigin(mButtonText.getGlobalBounds().size / 2.0f);
	mButtonShape.setFillColor(sf::Color::Black);
}

cNextLevelButtonUI::~cNextLevelButtonUI()
{
}
