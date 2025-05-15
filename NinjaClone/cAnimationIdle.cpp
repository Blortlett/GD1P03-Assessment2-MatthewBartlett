/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationIdle]
Description : [The cAnimationIdle class contains the data and functions necessary to and dispaly the player idle-state graphics. This should be a member of and called by a cAnimator object]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cAnimationIdle.h"

cAnimationIdle::cAnimationIdle()
{
    // Animation setup
    mTotalFrames = sf::Vector2u(1, 1);
    mFrameSize = sf::Vector2i(300, 324);
    LoadSpriteSheet("Assets/Sprites/StickmanIdle.png");

    mCurrentFrame = sf::Vector2u(0, 0);
}

cAnimationIdle::~cAnimationIdle()
{
}

void cAnimationIdle::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // Set sprite position
    mSprite->setPosition(PlayerPosition);
}

void cAnimationIdle::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*mSprite);
}
