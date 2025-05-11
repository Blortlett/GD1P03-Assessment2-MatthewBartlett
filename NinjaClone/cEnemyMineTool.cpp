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
	std::cout << "Tool position x: " << mShape->getPosition().x << "    y: " << mShape->getPosition().y << std::endl;
	cMine* enemyMine = new cMine(mShape->getPosition());
	mLevelPlatformsList.AddEnemyMine(enemyMine);
	return nullptr;
}

void cEnemyMineTool::UseTool(sf::Vector2f& mousePos)
{
}
