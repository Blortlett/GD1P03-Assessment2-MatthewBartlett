/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cKeyAnimation]
Description : [The KeyAnimation class contains the data and functions necessary to animate and dispaly the key graphics. This should be a member of and called by a cAnimator object]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cKeyAnimation.h"

cKeyAnimation::cKeyAnimation(sf::Vector2f position)
{
    // Animation setup
    mTotalFrames = sf::Vector2u(23, 1);
    mFrameSize = sf::Vector2i(32, 32);
    LoadSpriteSheet("Assets/Sprites/Objects/Key.png");
    mFrameDuration = 0.15f;
    mAnimationTime = 0.0f;
    mCurrentFrame = sf::Vector2u(0, 0);

    mSprite->setPosition(position);
    SetScale(sf::Vector2f(1, 1));
    mSprite->setOrigin(mSprite->getLocalBounds().size / 2.0f);
}

cKeyAnimation::~cKeyAnimation()
{
    delete mSprite;
}

void cKeyAnimation::AnimateKey(float DeltaSeconds)
{
    // Accumulate time
    mAnimationTime += DeltaSeconds;

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

void cKeyAnimation::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*mSprite);
}