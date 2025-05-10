#include "cApplicationManager.h"

cApplicationManager::cApplicationManager()
{
	// Get LevelExitDoor open/closed sprites
	mLevelExitClosedTex.loadFromFile("Assets/Sprites/LevelBlocks/LevelExitClosed.png");
	mLevelExitClosedSprite = new sf::Sprite(mLevelExitClosedTex);
	mLevelExitOpenTex.loadFromFile("Assets/Sprites/LevelBlocks/LevelExitOpen.png");
	mLevelExitOpenSprite = new sf::Sprite(mLevelExitOpenTex);

	// get font
	if (!mGameFont.openFromFile("Assets/Fonts/TypeLightSans-KV84p.otf"))
	{
		std::cerr << "Failed to load title font!" << std::endl;
	}
}

cApplicationManager::~cApplicationManager()
{
	delete mLevelExitClosedSprite;
	delete mLevelExitOpenSprite;
}

const std::string cApplicationManager::GetNextLevelName()
{
	mLevelCount++;
	std::string nextLevelName = mLevelNames[mLevelCount];
	return nextLevelName;
}

void cApplicationManager::ResetGameplayVariables()
{
	mIsDoorUnlocked = false;
	mIsLevelComplete = false;
}

void cApplicationManager::ResetLevelProgress()
{
	mLevelCount = 0;
}
