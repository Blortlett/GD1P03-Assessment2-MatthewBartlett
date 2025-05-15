/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEnemyMineTool]
Description : [cEnemyMineTool allows placing mines in a level structure]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cEnemyMineTool.h"

cEnemyMineTool::cEnemyMineTool(cLevelPlatformsList& levelPlatformList)
	: mLevelPlatformsList(levelPlatformList)
{
	mShape = new sf::RectangleShape(mRectSize);
	mShape->setOrigin(sf::Vector2f(mRectSize / 2.0f));
	mShape->setFillColor(sf::Color::Red);
}

void cEnemyMineTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos)
{
	mShape->setPosition(mousePos);
}

void cEnemyMineTool::DrawToolToScreen(sf::RenderWindow& window)
{
	window.draw(*mShape);
}

cPlatformRect* cEnemyMineTool::CompleteUseTool()
{
	cMine* enemyMine = new cMine(mShape->getPosition());
	mLevelPlatformsList.AddEnemyMine(enemyMine);
	return nullptr;
}

void cEnemyMineTool::UseTool(sf::Vector2f& mousePos)
{
}
