/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationSliding]
Description : [The cAnimationSliding class contains the data and functions necessary to and dispaly and animate the player sliding-state graphics. This should be a member of and called by a cAnimator object]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cAnimationSliding.h"

cAnimationSliding::cAnimationSliding()
{
    // Animation setup
    mTotalFrames = sf::Vector2u(1, 1);
    mFrameSize = sf::Vector2i(254, 298);
    LoadSpriteSheet("Assets/Sprites/StickmanSlide.png");
    mFrameDuration = 0.15f;
    mAnimationTime = 0.0f;
    mCurrentFrame = sf::Vector2u(0, 0);


}

cAnimationSliding::~cAnimationSliding()
{
}

void cAnimationSliding::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // Set sprite position
    mSprite->setPosition(PlayerPosition);
}

void cAnimationSliding::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*mSprite);
}
