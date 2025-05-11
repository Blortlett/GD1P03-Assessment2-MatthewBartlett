#include "cGameManager.h"

cGameManager::cGameManager(sf::RenderWindow& window, cPlayerInput& playerInput, cLevelPlatformsList& platformsList, cFileInterface& fileInterface)
    : mPlayerInput(playerInput)
    , mPlayerCharacter(sf::Vector2f(250, 600), playerInput)
    , mGameWindow(window)
    , mDeltaSeconds(0.0f)
    , mPlatformsList(platformsList)
    , mLevelCompleteUI(window, platformsList, fileInterface)
{

}

cGameManager::~cGameManager()
{
}

void cGameManager::GameTick()
{
    RefreshDeltaTime();
    //Draw Platforms
    mPlatformsList.DrawPlatforms(mGameWindow, mDeltaSeconds);
    mPlatformsList.CheckCollisions(mPlayerCharacter);
    //Draw Enemies
    mPlatformsList.DrawEnemies(mGameWindow, mDeltaSeconds);
    mPlatformsList.CheckEnemyCollisions(mPlayerCharacter);
    //Draw Player
    mPlayerCharacter.Update(mDeltaSeconds);
    mPlayerCharacter.Draw(mGameWindow);
    //Draw/UpdateUI
    mLevelCompleteUI.Update();
}

void cGameManager::DrawOnlyTick()
{
    mPlatformsList.DrawPlatforms(mGameWindow, mDeltaSeconds);
    mPlayerCharacter.Draw(mGameWindow);
}

void cGameManager::HandleSystemInputs()
{
    if (cApplicationManager::GetInstance().IsMainMenuActive()) return; // Do not open pause menu at main menu screen
    // Handle Pause Input. Do not want to be able to hold key
    if (mPlayerInput.IsPauseButtonPressed() && !mPauseKeyHeld)
    {
        if (!cApplicationManager::GetInstance().IsGamePaused())
        {
            // pause game
            cApplicationManager::GetInstance().SetGameRunning(false);
            cApplicationManager::GetInstance().SetGamePaused(true);
            mPauseKeyHeld = true;
        }
        else // else game is paused so...
        {
            // unpause game
            cApplicationManager::GetInstance().SetGameRunning(true);
            cApplicationManager::GetInstance().SetGamePaused(false);
            mPauseKeyHeld = true;
        }
    }
    else if (!mPlayerInput.IsPauseButtonPressed() && mPauseKeyHeld)
    {
        mPauseKeyHeld = false;
    }
    // Handle Debug Key Input. Do not want to be able to hold key
    if (mPlayerInput.IsDebugButtonPressed() && !mDebugKeyHeld)
    {
        bool debugModeActive = cApplicationManager::GetInstance().IsDebugModeActive();
        cApplicationManager::GetInstance().SetIsDebugModeActive(!debugModeActive);
        mDebugKeyHeld = true;
    }
    else if(!mPlayerInput.IsDebugButtonPressed() && mDebugKeyHeld)
    {
        mDebugKeyHeld = false;
    }
}

void cGameManager::RefreshDeltaTime()
{
    mDeltaTime = mClock.restart();
    mDeltaSeconds = mDeltaTime.asSeconds();
}