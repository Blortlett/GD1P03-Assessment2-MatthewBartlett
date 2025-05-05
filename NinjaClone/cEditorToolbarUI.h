#pragma once
#include <SFML/Graphics.hpp>
#include "cFileInterface.h"
#include "cRectPlatformToolButton.h"
#include "cToolButtonSpawnPoint.h"
#include "cToolButtonLevelExit.h"
#include "cSaveButton.h"
#include "cLoadButton.h"
#include "cLevelPlatformsList.h"


class cEditorToolbarUI {
public:
    cEditorToolbarUI(sf::RenderWindow& window, cEditorDrawTool& _DrawTool, cLevelPlatformsList& platformsList, cFileInterface& fileInterface);
    void Update();
    void Draw();
private:
    cEditorDrawTool& UserDrawTool;
    sf::RenderWindow& mMainWindow;

    // Tool Buttons
    cRectPlatformToolButton mButtonRectangleTool;
    cToolButtonSpawnPoint mButtonSpawnPointTool;
    cToolButtonLevelExit mButtonLevelExitTool;
    // Save/Load Buttons
    cSaveButton mSaveButton;
    cLoadButton mLoadButton;

    // Toolbar Window
    sf::RenderWindow mToolbarWindow;

    // Background Image
    sf::Texture mBackgroundTexture;
    sf::Sprite* mUIBackground;
};