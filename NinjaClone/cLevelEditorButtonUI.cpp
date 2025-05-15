/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevelEditorButtonUI]
Description : [cLevelEditorButtonUI provides a button for the player to push to start the level editor from the main menu]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cLevelEditorButtonUI.h"

cLevelEditorButtonUI::cLevelEditorButtonUI(sf::Vector2f position, sf::Vector2f size, cGameManager& gameManager, cFileInterface& fileInterface, cEditorToolbarUI& editorToolbar)
	: cButtonUI(position, size)
	, mText(mBodyFont, "LEVEL EDITOR", 20U)
	, mGameManager(gameManager)
	, mFileInterface(fileInterface)
	, mEditorToolbar(editorToolbar)
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
	mFileInterface.LoadLevelByName("BlankLevel");
	mEditorToolbar.OpenToolbar();
	cAudioPlayer::GetInstance().PlayEditorMusic();
}

void cLevelEditorButtonUI::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
