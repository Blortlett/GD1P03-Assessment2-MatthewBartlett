#pragma once
#include "cEmptyPlatformTool.h"
#include "cRectPlatformTool.h"
#include "cSpawnPlatformTool.h"
#include "cLevelExitTool.h"
#include <SFML/Graphics.hpp>
#include "cLevelPlatformsList.h"
#include "cPlayerInput.h"

class cEditorDrawTool {
public:
    cEditorDrawTool(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& platformsList);
    enum class ToolType {
        ToolMode_None,
        ToolMode_Rect,
        ToolMode_SpawnPoint,
        ToolMode_LevelExit
    };
    void SetTool(ToolType type);
    void UpdateCursor(sf::RenderWindow& window, sf::Vector2f mousePos);
    void UseTool(sf::Vector2f& mousePos);
    void DrawCursorToScreen(sf::RenderWindow& window);
    void CompleteUseTool();
private:
    cPlayerInput& mPlayerInput;
    sf::RenderWindow& mMainWindow;

    // Current Tool Holder
    cBaseDrawTool* mActiveTool;
    // Editor Tools
    cEmptyPlatformTool mEmptyTool;
    cRectPlatformTool mRectangleTool;
    cSpawnPlatformTool mSpawnPlatformTool;
    cLevelExitTool mLevelExitTool;

    // DrawGrid
    float mGridSize = 24;

    // Current Game Level data
    cLevelPlatformsList& mPlatformsList; // Platforms

    // Draw tool helpers
    bool mIsDrawing = false;
};