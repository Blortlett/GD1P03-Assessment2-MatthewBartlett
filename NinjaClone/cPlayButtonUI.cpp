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
	cApplicationManager::GetInstance().SetGameRunning(true);
	cApplicationManager::GetInstance().SetMainMenuActive(false);
	mGameManager.RespawnPlayer();
}

void cPlayButtonUI::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
