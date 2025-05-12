#include "cBouncySquareTool.h"

cBouncySquareTool::cBouncySquareTool(cLevelPlatformsList& levelPlatformList)
	: mLevelPlatformsList(levelPlatformList)
{
	mShape = new sf::RectangleShape(mRectSize);
	mShape->setOrigin(sf::Vector2f(mRectSize / 2.0f));
	mShape->setFillColor(sf::Color::Red);
}

void cBouncySquareTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos)
{
	mShape->setPosition(mousePos);
}

void cBouncySquareTool::DrawToolToScreen(sf::RenderWindow& window)
{
	window.draw(*mShape);
}

cPlatformRect* cBouncySquareTool::CompleteUseTool()
{
	cBouncySquare* BouncySquare = new cBouncySquare(mShape->getPosition());
	mLevelPlatformsList.AddBouncySquare(BouncySquare);
	return nullptr;
}

void cBouncySquareTool::UseTool(sf::Vector2f& mousePos)
{
}
