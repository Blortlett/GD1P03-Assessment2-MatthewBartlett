#include "cReturnToMainMenu.h"

cReturnToMainMenu::cReturnToMainMenu(cLevelPlatformsList& platformsList, cEditorToolbarUI& editorToolbar)
	: cButtonUI(sf::Vector2f(1366 / 2, (768 / 2) + 90), sf::Vector2f(300, 100))
	, mText(cApplicationManager::GetInstance().GetFont(), "MAIN MENU", 10U)
	, mPlatformsList(platformsList)
	, mEditorUI(editorToolbar)
{
	// Center text
	mText.setPosition(mPosition);
	mText.setCharacterSize(20);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
	mText.setFillColor(sf::Color::Black);
}

cReturnToMainMenu::~cReturnToMainMenu()
{
}

void cReturnToMainMenu::OnButtonClick()
{
	mEditorUI.CloseToolbar();
	// Delete Active Level
	mPlatformsList.ClearList();
	cApplicationManager::GetInstance().ResetLevelProgress();
	cApplicationManager::GetInstance().SetGameRunning(false);
	cApplicationManager::GetInstance().SetGamePaused(false);
	cApplicationManager::GetInstance().SetMainMenuActive(true);
	cApplicationManager::GetInstance().SetLevelEditorRunning(false);
	cAudioPlayer::GetInstance().PlayMenuMusic();
}

void cReturnToMainMenu::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
