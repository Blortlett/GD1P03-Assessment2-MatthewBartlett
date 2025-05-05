#include "cApplicationManager.h"

cApplicationManager::cApplicationManager()
{
	mLevelExitClosedTex.loadFromFile("Assets/Sprites/LevelBlocks/LevelExitClosed.png");
	mLevelExitClosedSprite = new sf::Sprite(mLevelExitClosedTex);
	mLevelExitOpenTex.loadFromFile("Assets/Sprites/LevelBlocks/LevelExitOpen.png");
	mLevelExitOpenSprite = new sf::Sprite(mLevelExitOpenTex);
}

cApplicationManager::~cApplicationManager()
{
	delete mLevelExitClosedSprite;
	delete mLevelExitOpenSprite;
}
