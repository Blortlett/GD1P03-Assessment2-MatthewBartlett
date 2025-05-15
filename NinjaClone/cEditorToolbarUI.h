/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEditorToolbarUI]
Description : [cEditorToolbarUI provied an open/closeable menu UI system for the player to interact with while building levels]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include "cFileInterface.h"
#include "cRectPlatformToolButton.h"
#include "cToolButtonSpawnPoint.h"
#include "cToolButtonLevelExit.h"
#include "cToolButtonKeyObject.h"
#include "cToolButtonEnemyMine.h"
#include "cToolButtonBouncySquare.h"
#include "cSaveButton.h"
#include "cLoadButton.h"
#include "cLevelPlatformsList.h"


class cEditorToolbarUI {
public:
    cEditorToolbarUI(sf::RenderWindow& window, cEditorDrawTool& _DrawTool, cLevelPlatformsList& platformsList, cFileInterface& fileInterface);
    void OpenToolbar();
    void CloseToolbar();

    void Update();
    void Draw();
private:
    cEditorDrawTool& UserDrawTool;
    sf::RenderWindow& mMainWindow;

    sf::Vector2f mButtonOffset = { 25.f , 0 };
    // Tool Buttons - Level Objects
    cRectPlatformToolButton mButtonRectangleTool;
    cToolButtonSpawnPoint mButtonSpawnPointTool;
    cToolButtonLevelExit mButtonLevelExitTool;
    cToolButtonKeyObject mButtonLevelKeyTool;
    cToolButtonBouncySquare mButtonBouncySquareTool;
    // Tool Buttons - Enemies
    cToolButtonEnemyMine mButtonEnemyMineTool;
    // Save/Load Buttons
    cSaveButton mSaveButton;
    cLoadButton mLoadButton;

    // Toolbar Window
    sf::RenderWindow* mToolbarWindow;

    // Background Image
    sf::Texture mBackgroundTexture;
    sf::Sprite* mUIBackground;
};