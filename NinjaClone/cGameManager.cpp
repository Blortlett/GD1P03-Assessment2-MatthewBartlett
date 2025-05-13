#include "cGameManager.h"
#include "cLevelCompleteScreenUI.h"

cGameManager::cGameManager(sf::RenderWindow& window, cPlayerInput& playerInput, cLevelPlatformsList& platformsList, cFileInterface& fileInterface)
    : mPlayerInput(playerInput)
    , mPlayerCharacter(sf::Vector2f(250, 600), playerInput)
    , mGameWindow(window)
    , mDeltaSeconds(0.0f)
    , mPlatformsList(platformsList)
{
    mLevelCompleteUI = new cLevelCompleteScreenUI(window, platformsList, fileInterface, *this);
}

cGameManager::~cGameManager()
{
    delete mLevelCompleteUI;
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
    mLevelCompleteUI->Update();
}

void cGameManager::DrawOnlyTick()
{
    RefreshDeltaTime();
    mPlatformsList.DrawPlatforms(mGameWindow, mDeltaSeconds);
    mPlayerCharacter.Draw(mGameWindow);
}

void cGameManager::DrawDeathTick()
{
    RefreshDeltaTime();
    mDeathScreenTimer += mDeltaSeconds;
    mDeathFlashTimer += mDeltaSeconds;
    if (mDeathScreenTimer >= mDeathScreenTimeMax)
    {
        // Respawn player and reset game variables
        RespawnPlayer();
        mDeathScreenTimer = 0.f;
    }
    if (mDeathFlashTimer >= mDeathFlashTimeMax)
    {
        // Toggle Draw character
        mDrawCharacterOnDeath = !mDrawCharacterOnDeath;
        mDeathFlashTimer = 0.f;
    }
    // Draw character on death - if supposed to
    if (mDrawCharacterOnDeath)
    {
        mPlayerCharacter.Draw(mGameWindow);
    }
    mPlatformsList.DrawEnemies(mGameWindow, mDeltaSeconds);
    mPlatformsList.DrawPlatforms(mGameWindow, mDeltaSeconds);
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

void cGameManager::RespawnPlayer()
{
    cApplicationManager::GetInstance().ResetGameplayVariables();
    sf::Vector2f spawnPos = mPlatformsList.GetPlayerSpawnPos();
    mPlayerCharacter.KillVelocity();
    mPlayerCharacter.MovePlayerCharacterPosition(spawnPos);
}

