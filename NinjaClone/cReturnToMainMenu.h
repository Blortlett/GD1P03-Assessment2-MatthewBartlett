/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cReturnToMainMenu]
Description : [cReturnToMainMenu provides a button for the player to push to return to the MainMenu]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"
#include "cLevelPlatformsList.h"
#include "cAudioPlayer.h"
#include "cEditorToolbarUI.h"

class cReturnToMainMenu : public cButtonUI
{
private:
	// Existing items
	cEditorToolbarUI& mEditorUI;
	cLevelPlatformsList& mPlatformsList;

	// Button items
	sf::Text mText;
public:
	cReturnToMainMenu(cLevelPlatformsList& platformsList, cEditorToolbarUI& editorToolbar);
	~cReturnToMainMenu();

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
};