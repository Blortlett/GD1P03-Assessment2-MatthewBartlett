#include "cLevelExit.h"

cLevelExit::cLevelExit(sf::Vector2f position)
	: mDoorClosedSprite(cApplicationManager::GetInstance().mLevelExitClosedSprite)
	, mDoorOpenSprite(cApplicationManager::GetInstance().mLevelExitOpenSprite)
	, mExitCollider(sf::FloatRect(position, mDoorClosedSprite->getLocalBounds().size))
	, mDebugWidget(mExitCollider)
{
	mDoorClosedSprite->setPosition(position);
	mDoorOpenSprite->setPosition(position);
	
	mDoorClosedSprite->setOrigin(mDoorClosedSprite->getLocalBounds().size / 2.0f);
	mDoorOpenSprite->setOrigin(mDoorOpenSprite->getLocalBounds().size / 2.0f);
}

void cLevelExit::Draw(sf::RenderWindow& renderWindow)
{
	mDebugWidget.DrawWidget(renderWindow);
	// Ugly doing this every while loop of game... Time restrictions has me caring little for it so i done it all over the place and made shit uggz g
	if (cApplicationManager::GetInstance().IsDoorUnlocked())
	{
		renderWindow.draw(*mDoorOpenSprite);
	}
	else
	{
		renderWindow.draw(*mDoorClosedSprite);
	}
}

bool cLevelExit::CheckCollideWithPlayer(cCharacter& character)
{
	sf::Vector2f collisionDirection = sf::Vector2f(0, 0); // going to ignore this idgaf about it

	return mExitCollider.CheckCollision(character.GetCollider(), collisionDirection, 0.0f);
}
