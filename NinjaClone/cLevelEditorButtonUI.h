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
#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"
#include "cAudioPlayer.h"
#include "cGameManager.h"
#include "cFileInterface.h"
#include "cEditorToolbarUI.h"

class cMainMenu;

class cLevelEditorButtonUI : public cButtonUI
{
public:
	cLevelEditorButtonUI(sf::Vector2f position, sf::Vector2f size, cGameManager& gameManager, cFileInterface& fileInterface, cEditorToolbarUI& editorToolbar);
	~cLevelEditorButtonUI();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	// Existing Objects
	cGameManager& mGameManager;
	cFileInterface& mFileInterface;
	cEditorToolbarUI& mEditorToolbar;

	// Button Items
	sf::Font mBodyFont;
	sf::Text mText;
};