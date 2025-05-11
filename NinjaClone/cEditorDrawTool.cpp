#include "cEditorDrawTool.h"

cEditorDrawTool::cEditorDrawTool(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& platformsList)
	: mMainWindow(mainWindow)
	, mActiveTool(nullptr)
	, mPlayerInput(playerInput)
	, mPlatformsList(platformsList)
	, mLevelExitTool(platformsList)
	, mLevelKeyTool(platformsList)
	, mEnemyMineTool(platformsList)
{
	SetTool(cEditorDrawTool::ToolType::ToolMode_None);
}

void cEditorDrawTool::SetTool(ToolType type)
{
	switch (type)
	{
	case cEditorDrawTool::ToolType::ToolMode_None:
		mActiveTool = &mEmptyTool;
		break;
	case cEditorDrawTool::ToolType::ToolMode_Rect:
		mActiveTool = &mRectangleTool;
		break;
	case cEditorDrawTool::ToolType::ToolMode_SpawnPoint:
		mActiveTool = &mSpawnPlatformTool;
		break;
	case cEditorDrawTool::ToolType::ToolMode_LevelExit:
		mActiveTool = &mLevelExitTool;
		break;
	case cEditorDrawTool::ToolType::ToolMode_LevelKey:
		mActiveTool = &mLevelKeyTool;
		break;
	case cEditorDrawTool::ToolType::ToolMode_EnemyMine:
		mActiveTool = &mEnemyMineTool;
		break;
	case cEditorDrawTool::ToolType::ToolMode_EnemyMushroom:
		mActiveTool = &mLevelKeyTool;
		break;

	}
}

void cEditorDrawTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f toolPosition)
{
	if (mPlayerInput.IsLeftClickPressed() && window.hasFocus())
	{
		UseTool(toolPosition);
		mIsDrawing = true;
	}
	else
	{
		if (mIsDrawing)
		{
			CompleteUseTool();
			mIsDrawing = false;
		}
		else
		{
			mActiveTool->UpdateCursor(window, toolPosition);
		}
	}
}

void cEditorDrawTool::UseTool(sf::Vector2f& toolPosition)
{
	toolPosition.x += mGridSize;
	toolPosition.y += mGridSize;
	mActiveTool->UseTool(toolPosition);
}

void cEditorDrawTool::DrawCursorToScreen(sf::RenderWindow& window)
{
	mActiveTool->DrawToolToScreen(window);
}

void cEditorDrawTool::CompleteUseTool()
{
	cPlatformRect* platform = mActiveTool->CompleteUseTool();
	mPlatformsList.AddPlatform(platform);
}

