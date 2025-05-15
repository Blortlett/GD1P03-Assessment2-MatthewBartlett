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
#pragma once
#include "cEditorDrawTool.h"
#include "cEditorToolbarUI.h"
#include "cPlayerInput.h"
#include "cFileInterface.h"

class cLevelEditorManager
{
public:
	cLevelEditorManager(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& platformsList, cFileInterface& fileInterface);
	~cLevelEditorManager();

	cEditorToolbarUI& GetToolbarUI() { return mToolbar; }

	void Update();
	void Draw();
private:
	cEditorDrawTool mDrawTool;
	cEditorToolbarUI mToolbar;
	sf::RenderWindow& mMainWindow;

	// DrawGrid
	float mGridSize = 24;
};