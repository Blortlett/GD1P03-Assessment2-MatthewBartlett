#include "cSpawnPlatformTool.h"

cSpawnPlatformTool::cSpawnPlatformTool(cLevelPlatformsList& levelPlatformList)
	: mLevelPlatformsList(levelPlatformList)
{
	mShape = new sf::RectangleShape(mRectSize);
	mShape->setOrigin(sf::Vector2f(mRectSize / 2.0f));
	mShape->setFillColor(sf::Color::Green);
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
	std::cout << "x: " << mShape->getPosition().x << "y: " << mShape->getPosition().y << std::endl;
	std::cout << "x: " << SpawnPlatform->GetPosition().x << "y: " << SpawnPlatform->GetPosition().y << std::endl;
	return nullptr;
}

void cSpawnPlatformTool::UseTool(sf::Vector2f& mousePos)
{
}
