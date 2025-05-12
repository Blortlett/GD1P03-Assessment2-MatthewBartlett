#include "cSpawnPlatformTool.h"

cSpawnPlatformTool::cSpawnPlatformTool(cLevelPlatformsList& levelPlatformList)
	: mLevelPlatformsList(levelPlatformList)
{
	mShape = new sf::RectangleShape(mRectSize);
	mShape->setOrigin(sf::Vector2f(mRectSize / 2.0f));
	mShape->setFillColor(sf::Color::Black);
}

void cSpawnPlatformTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos)
{
	mShape->setPosition(mousePos);
}

void cSpawnPlatformTool::DrawToolToScreen(sf::RenderWindow& window)
{
	window.draw(*mShape);
}

cPlatformRect* cSpawnPlatformTool::CompleteUseTool()
{
	cPlatformLevelStart* SpawnPlatform = new cPlatformLevelStart(mShape->getPosition());
	mLevelPlatformsList.AddPlayerSpawn(SpawnPlatform);
	return nullptr;
}

void cSpawnPlatformTool::UseTool(sf::Vector2f& mousePos)
{
}
