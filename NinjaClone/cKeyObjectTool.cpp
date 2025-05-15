/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cKeyObjectTool]
Description : [cKeyObjectTool allows placing the level key in a level structure]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cKeyObjectTool.h"

cKeyObjectTool::cKeyObjectTool(cLevelPlatformsList& levelPlatformList)
	: mLevelPlatformsList(levelPlatformList)
{
	mShape = new sf::RectangleShape(mRectSize);
	mShape->setOrigin(sf::Vector2f(mRectSize / 2.0f));
	mShape->setFillColor(sf::Color::White);
}

cKeyObjectTool::~cKeyObjectTool()
{

}

void cKeyObjectTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos)
{
	mShape->setPosition(mousePos);
}

void cKeyObjectTool::DrawToolToScreen(sf::RenderWindow& window)
{
	window.draw(*mShape);
}

cPlatformRect* cKeyObjectTool::CompleteUseTool()
{
	cKeyObject* levelKey = new cKeyObject(mShape->getPosition());
	mLevelPlatformsList.AddLevelKey(levelKey);
	return nullptr;
}

void cKeyObjectTool::UseTool(sf::Vector2f& mousePos)
{
}