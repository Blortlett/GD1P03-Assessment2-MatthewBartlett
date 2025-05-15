/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationRunning]
Description : [The cAnimationRunning class contains the data and functions necessary to and dispaly and animate the player running-state graphics. This should be a member of and called by a cAnimator object]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cAnimationRunning.h"

cAnimationRunning::cAnimationRunning()
{
    // Animation setup
    mTotalFrames = sf::Vector2u(4, 1);
    mFrameSize = sf::Vector2i(345, 256);
    LoadSpriteSheet("Assets/Sprites/StickmanRun.png");
    mFrameDuration = 0.13f;
    mAnimationTime = 0.0f;
    mCurrentFrame = sf::Vector2u(0, 0);
}

cAnimationRunning::~cAnimationRunning()
{
}

void cAnimationRunning::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // Accumulate time
    mAnimationTime += DeltaSeconds;

    // Set sprite position
    mSprite->setPosition(PlayerPosition);

    // Check if it's time to switch frames
    if (mAnimationTime >= mFrameDuration)
    {
        mAnimationTime -= mFrameDuration;  // Reset timer
        mCurrentFrame.x = (mCurrentFrame.x + 1) % mTotalFrames.x;  // Cycle through frames

        mSpriteRect.position = (sf::Vector2i(mFrameSize.x * (1 + mCurrentFrame.x), 0));
        mSpriteRect.size = mFrameSize;

        // Update sprite rectangle
        mSprite->setTextureRect(mSpriteRect);
    }
}

void cAnimationRunning::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*mSprite);
}
