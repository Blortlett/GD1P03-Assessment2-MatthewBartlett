/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayButtonUI]
Description : [cPlayButtonUI provides a button for the player to push to start the game from the main menu]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cPlayButtonUI.h"

cPlayButtonUI::cPlayButtonUI(sf::Vector2f position, sf::Vector2f size, cFileInterface& fileInterface, cGameManager& gameManager)
	: cButtonUI(position, size)
	, mText(mBodyFont, "PLAY", 6U)
	, mFileInterface(fileInterface)
	, mBodyFont(cApplicationManager::GetInstance().GetFont())
	, mGameManager(gameManager)
{
	// get font
	mBodyFont = cApplicationManager::GetInstance().GetFont();
	// Do the crap from cMainMenu.cpp
	mText.setString("PLAY");
	mText.setCharacterSize(20);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cPlayButtonUI::OnButtonClick()
{
	mFileInterface.LoadLevelByName("Level1");
	cApplicationManager::GetInstance().SetMainMenuActive(false);
	cApplicationManager::GetInstance().SetGameRunning(true);
	mGameManager.RespawnPlayer();
	cAudioPlayer::GetInstance().PlayFirstLevelMusic();
}

void cPlayButtonUI::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
