#include "cEditorToolbarUI.h"


cEditorToolbarUI::cEditorToolbarUI(sf::RenderWindow& window, cEditorDrawTool& _DrawTool, cLevelPlatformsList& platformsList, cFileInterface& fileInterface)
	: mMainWindow(window), UserDrawTool(_DrawTool)
	, mToolbarWindow(nullptr)
	, mButtonRectangleTool(sf::Vector2f(15.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mButtonSpawnPointTool(sf::Vector2f(55.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mButtonLevelExitTool(sf::Vector2f(95.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mButtonLevelKeyTool(sf::Vector2f(135.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mButtonEnemyMineTool(sf::Vector2f(15.0f, 50.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mButtonBouncySquareTool(sf::Vector2f(55.0f, 50.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mSaveButton(sf::Vector2f(15.0f, 226.0f), sf::Vector2f(25.0f, 25.0f), fileInterface, platformsList)
	, mLoadButton(sf::Vector2f(45.0f, 226.0f), sf::Vector2f(25.0f, 25.0f), fileInterface, platformsList)
{
	// load image
	mBackgroundTexture.loadFromFile("Assets/Sprites/UI/Toolbar/ToolbarBackground.png");
	mUIBackground = new sf::Sprite(mBackgroundTexture);
}

void cEditorToolbarUI::OpenToolbar()
{
	mToolbarWindow = new sf::RenderWindow(sf::VideoMode({ 256, 256 }), "Editor Toolbar");
	mToolbarWindow->setPosition(mMainWindow.getPosition() + sf::Vector2i(mMainWindow.getSize().x + 2, 0));
}

void cEditorToolbarUI::CloseToolbar()
{
	delete mToolbarWindow;
	mToolbarWindow = nullptr;
}

void cEditorToolbarUI::Update()
{
	if (!mToolbarWindow) return;
	// Buttons
	mButtonRectangleTool.Update(*mToolbarWindow);
	mButtonSpawnPointTool.Update(*mToolbarWindow);
	mButtonLevelExitTool.Update(*mToolbarWindow);
	mButtonLevelKeyTool.Update(*mToolbarWindow);
	mButtonEnemyMineTool.Update(*mToolbarWindow);
	mButtonBouncySquareTool.Update(*mToolbarWindow);
}

void cEditorToolbarUI::Draw() 
{
	if (!mToolbarWindow) return;
	// Draw Background
	mToolbarWindow->draw(*mUIBackground);
	// Draw Buttons
	mButtonRectangleTool.Draw(*mToolbarWindow);
	mButtonSpawnPointTool.Draw(*mToolbarWindow);
	mButtonLevelExitTool.Draw(*mToolbarWindow);
	mButtonLevelKeyTool.Draw(*mToolbarWindow);
	mButtonEnemyMineTool.Draw(*mToolbarWindow);
	mButtonBouncySquareTool.Draw(*mToolbarWindow);

	mSaveButton.Draw(*mToolbarWindow);
	mLoadButton.Draw(*mToolbarWindow);

	mToolbarWindow->display();
}
