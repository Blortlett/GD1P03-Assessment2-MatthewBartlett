#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"
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