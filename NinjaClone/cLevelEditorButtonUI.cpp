#include "cLevelEditorButtonUI.h"

cLevelEditorButtonUI::cLevelEditorButtonUI(sf::Vector2f position, sf::Vector2f size)
	: cButtonUI(position, size)
	, mText(mBodyFont, "LEVEL EDITOR", 20U)
{
	// get font
	mBodyFont = cApplicationManager::GetInstance().GetFont();
	// Do the crap from cMainMenu.cpp
	mText.setString("LEVEL EDITOR");
	mText.setCharacterSize(20);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

cLevelEditorButtonUI::~cLevelEditorButtonUI()
{

}

void cLevelEditorButtonUI::OnButtonClick()
{
	cApplicationManager::GetInstance().SetMainMenuActive(false);
	cApplicationManager::GetInstance().SetLevelEditorRunning(true);
	cApplicationManager::GetInstance().SetGameRunning(true);

}

void cLevelEditorButtonUI::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
