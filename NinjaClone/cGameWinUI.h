#pragma once
#include "cApplicationManager.h"
#include "cReturnToMainMenu.h"
#include "cEditorToolbarUI.h"
#include "cGameManager.h"

class cGameWinUI
{
private:
	// Render Window
	sf::RenderWindow& mRenderWindow;
	// Title
	sf::Text mText;
	sf::Vector2f mTitlePosition = sf::Vector2f(1366 / 2, (768 / 2) - 150);
	// Buttons
	sf::Vector2f mButtonSize = sf::Vector2f(300, 100);
	sf::Vector2f mReturnToMenuButtonPosition = sf::Vector2f(1366 / 2, 300);
	cReturnToMainMenu mReturnToMenuButton;

public:
	cGameWinUI(sf::RenderWindow& renderWindow, cLevelPlatformsList& platformList, cEditorToolbarUI editorToolbar);
	~cGameWinUI() {}
	void Update();
};