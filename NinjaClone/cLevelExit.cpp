#include "cLevelExit.h"

cLevelExit::cLevelExit(sf::Vector2f position)
	: mExitCollider(sf::FloatRect(position, mSize))
	, mDoorClosedSprite(cApplicationManager::GetInstance().mLevelExitClosedSprite)
	, mDoorOpenSprite(cApplicationManager::GetInstance().mLevelExitOpenSprite)
{
	mDoorClosedSprite->setPosition(position);
	mDoorOpenSprite->setPosition(position);
}

void cLevelExit::Draw(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(*mDoorClosedSprite); // gotta draw the active sprite here not only door closed...
}
