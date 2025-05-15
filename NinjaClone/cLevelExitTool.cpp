/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevelExitTool]
Description : [cLevelExitTool allows placing the level exit in a level structure]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cLevelExitTool.h"

cLevelExitTool::cLevelExitTool(cLevelPlatformsList& levelPlatformList)
	: mLevelPlatformsList(levelPlatformList)
{
	mShape = new sf::RectangleShape(mRectSize);
	mShape->setOrigin(sf::Vector2f(mRectSize / 2.0f));
	mShape->setFillColor(sf::Color::Magenta);
}

void cLevelExitTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos)
{
	mShape->setPosition(mousePos);
}

void cLevelExitTool::DrawToolToScreen(sf::RenderWindow& window)
{
	window.draw(*mShape);
}

cPlatformRect* cLevelExitTool::CompleteUseTool()
{
	cLevelExit* levelExit = new cLevelExit(mShape->getPosition());
	mLevelPlatformsList.AddLevelExit(levelExit);
	return nullptr;
}

void cLevelExitTool::UseTool(sf::Vector2f& mousePos)
{
}
