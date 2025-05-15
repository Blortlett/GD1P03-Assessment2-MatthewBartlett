/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationWallslide]
Description : [The cAnimationWallslide class contains the data and functions necessary to and dispaly and animate the player Wallslide-state graphics. This should be a member of and called by a cAnimator object]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cAnimationWallslide.h"

cAnimationWallslide::cAnimationWallslide()
{
    // Animation setup
    mTotalFrames = sf::Vector2u(1, 1);
    mFrameSize = sf::Vector2i(127, 248);
    LoadSpriteSheet("Assets/Sprites/StickmanWallslide.png");
    mFrameDuration = 0.15f;
    mAnimationTime = 0.0f;
    mCurrentFrame = sf::Vector2u(0, 0);
    mSprite->setOrigin(sf::Vector2f(10, mFrameSize.y));
}

cAnimationWallslide::~cAnimationWallslide()
{
}

void cAnimationWallslide::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // Set sprite position
    mSprite->setPosition(PlayerPosition);
}

void cAnimationWallslide::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*mSprite);
}
