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