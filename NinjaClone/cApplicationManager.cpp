/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cApplicationManager]
Description : [This singleton class handles global variables and loads in textures for other classes - mostly UI stuff]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cApplicationManager.h"

cApplicationManager::cApplicationManager()
	: mEnemyMineSprite(mMineTexture)
	, mEnemyMushroomSprite(mMushroomManTexture)
	, mLoadIcon(mLoadIconTexture)
	, mSaveIcon(mSaveIconTexture)
	, mKeyIcon(mKeyIconTexture)
{
	// Get object sprites
	mLevelExitClosedTex.loadFromFile("Assets/Sprites/LevelBlocks/LevelExitClosed.png");
	mLevelExitClosedSprite = new sf::Sprite(mLevelExitClosedTex);
	mLevelExitOpenTex.loadFromFile("Assets/Sprites/LevelBlocks/LevelExitOpen.png");
	mLevelExitOpenSprite = new sf::Sprite(mLevelExitOpenTex);
	mMineTexture.loadFromFile("Assets/Sprites/Enemies/Mine.png");
	mEnemyMineSprite = sf::Sprite(mMineTexture);
	mMushroomManTexture.loadFromFile("Assets/Sprites/Enemies/Mushroom.png");
	mEnemyMushroomSprite = sf::Sprite(mMushroomManTexture);
	mLoadIconTexture.loadFromFile("Assets/Sprites/UI/Toolbar/LoadIcon.png");
	mLoadIcon = sf::Sprite(mLoadIconTexture);
	mSaveIconTexture.loadFromFile("Assets/Sprites/UI/Toolbar/SaveIcon.png");
	mSaveIcon = sf::Sprite(mSaveIconTexture);
	mKeyIconTexture.loadFromFile("Assets/Sprites/UI/Toolbar/Key.png");
	mKeyIcon = sf::Sprite(mKeyIconTexture);

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

const std::string cApplicationManager::GetCurrentLevelName()
{
	return mLevelNames[mLevelCount];
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
	mIsPlayerDead = false;
	mIsGameComplete = false;
}

void cApplicationManager::ResetLevelProgress()
{
	mLevelCount = 0;
}

bool cApplicationManager::IsGameWon()
{
	return mLevelCount + 1 >= mMaxLevel;
}
