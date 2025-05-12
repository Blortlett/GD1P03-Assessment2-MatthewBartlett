#include "cEditorToolbarUI.h"


cEditorToolbarUI::cEditorToolbarUI(sf::RenderWindow& window, cEditorDrawTool& _DrawTool, cLevelPlatformsList& platformsList, cFileInterface& fileInterface)
	: mMainWindow(window), UserDrawTool(_DrawTool)
	, mToolbarWindow(sf::VideoMode({ 256, 256 }), "Editor Toolbar")
	, mButtonRectangleTool(sf::Vector2f(15.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mButtonSpawnPointTool(sf::Vector2f(55.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mButtonLevelExitTool(sf::Vector2f(95.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mButtonLevelKeyTool(sf::Vector2f(135.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mButtonEnemyMineTool(sf::Vector2f(15.0f, 50.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mSaveButton(sf::Vector2f(15.0f, 226.0f), sf::Vector2f(25.0f, 25.0f), fileInterface, platformsList)
	, mLoadButton(sf::Vector2f(45.0f, 226.0f), sf::Vector2f(25.0f, 25.0f), fileInterface, platformsList)
{
	mToolbarWindow.setPosition(mMainWindow.getPosition() + sf::Vector2i(mMainWindow.getSize().x + 2, 0));
	// load image
	mBackgroundTexture.loadFromFile("Assets/Sprites/UI/Toolbar/ToolbarBackground.png");
	mUIBackground = new sf::Sprite(mBackgroundTexture);
}

void cEditorToolbarUI::Update()
{
	// Buttons
	mButtonRectangleTool.Update(mToolbarWindow);
	mButtonSpawnPointTool.Update(mToolbarWindow);
	mButtonLevelExitTool.Update(mToolbarWindow);
	mButtonLevelKeyTool.Update(mToolbarWindow);
	mButtonEnemyMineTool.Update(mToolbarWindow);
}

void cEditorToolbarUI::Draw() {
	mToolbarWindow.draw(*mUIBackground);
	// Buttons
	mButtonRectangleTool.Draw(mToolbarWindow);
	mButtonSpawnPointTool.Draw(mToolbarWindow);
	mButtonLevelExitTool.Draw(mToolbarWindow);
	mButtonLevelKeyTool.Draw(mToolbarWindow);
	mButtonEnemyMineTool.Draw(mToolbarWindow);

	mSaveButton.Draw(mToolbarWindow);
	mLoadButton.Draw(mToolbarWindow);

	mToolbarWindow.display();
}
