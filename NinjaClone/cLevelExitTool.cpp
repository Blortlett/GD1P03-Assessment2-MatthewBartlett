#include "cLevelExitTool.h"

cLevelExitTool::cLevelExitTool(cLevelPlatformsList& levelPlatformList)
	: mLevelPlatformsList(levelPlatformList)
{
	mShape = new sf::RectangleShape(mRectSize);
	mShape->setOrigin(sf::Vector2f(mRectSize / 2.0f));
	mShape->setFillColor(sf::Color::Blue);
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
