/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEditorDrawTool]
Description : [This class has all draw tools as member variables and provides a state machine to switch between editor tools]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cEditorDrawTool.h"

cEditorDrawTool::cEditorDrawTool(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& platformsList)
	: mMainWindow(mainWindow)
	, mActiveTool(nullptr)
	, mPlayerInput(playerInput)
	, mPlatformsList(platformsList)
	, mSpawnPlatformTool(platformsList)
	, mLevelExitTool(platformsList)
	, mLevelKeyTool(platformsList)
	, mEnemyMineTool(platformsList)
	, mBouncySquareTool(platformsList)
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
	case cEditorDrawTool::ToolType::ToolMode_BouncySquare:
		mActiveTool = &mBouncySquareTool;
		break;

	}
}

void cEditorDrawTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f toolPosition)
{
	// Right Click to delete platform
	if (mPlayerInput.IsRightClickPressed() && window.hasFocus())
	{
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
		mPlatformsList.TryDeletePlatform(mousePos);
	}

	// Left Click
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

