#include "cGameManager.h"

cGameManager::cGameManager(sf::RenderWindow& window, cPlayerInput& playerInput, cLevelPlatformsList& platformsList)
    : mPlayerInput(playerInput)
    , mPlayerCharacter(sf::Vector2f(250, 600), playerInput)
    , mGameWindow(window)
    , mDeltaSeconds(0.0f)
    , mPlatformsList(platformsList)
    , mLevelCompleteUI(window)
{

}

cGameManager::~cGameManager()
{
}

void cGameManager::GameTick()
{
    RefreshDeltaTime();

    mPlatformsList.DrawPlatforms(mGameWindow, mDeltaSeconds);
    mPlatformsList.CheckCollisions(mPlayerCharacter);

    mPlayerCharacter.Update(mDeltaSeconds);
    mPlayerCharacter.Draw(mGameWindow);

    mLevelCompleteUI.Update();
}

void cGameManager::RefreshDeltaTime()
{
    mDeltaTime = mClock.restart();
    mDeltaSeconds = mDeltaTime.asSeconds();
}