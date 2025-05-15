/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevelEditorManager]
Description : [cLevelEditorManager manages the level editor tool manager and toolbar]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cLevelEditorManager.h"

cLevelEditorManager::cLevelEditorManager(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& platformsList, cFileInterface& fileInterface)
	: mMainWindow(mainWindow)
	, mDrawTool(mainWindow, playerInput, platformsList)
	, mToolbar(mainWindow, mDrawTool, platformsList, fileInterface)

{

}

cLevelEditorManager::~cLevelEditorManager()
{
}

void cLevelEditorManager::Update()
{
	// Get mouse position
	sf::Vector2i mousePos = sf::Mouse::getPosition(mMainWindow);
	// Convert to float for calculations
	sf::Vector2f mousePosF = static_cast<sf::Vector2f>(mousePos);

	// Calculate grid-aligned tool position
	sf::Vector2f ToolPosition;
	ToolPosition.x = std::floor(mousePosF.x / mGridSize) * mGridSize;
	ToolPosition.y = std::floor(mousePosF.y / mGridSize) * mGridSize;

	// Update cursor with the tool position
	mDrawTool.UpdateCursor(mMainWindow, ToolPosition);
	mToolbar.Update();
}

void cLevelEditorManager::Draw()
{
	mDrawTool.DrawCursorToScreen(mMainWindow);
	mToolbar.Draw();
}
