/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimator]
Description : [Any object that would like to have animations should have a cAnimator member object attatched to it. This class can switch, animate and display animations]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cAnimator.h"

cAnimator::cAnimator()
    : mFaceLeftScale(sf::Vector2f(-0.11f, 0.11f))
    , mFaceRightScale(sf::Vector2f(0.11f, 0.11f))
{
    mCurrentAnimation = &mIdleAnimation;
}

cAnimator::~cAnimator()
{
}

void cAnimator::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    mCurrentAnimation->Animate(PlayerPosition, DeltaSeconds);
}

void cAnimator::Draw(sf::RenderWindow& renderWindow)
{
    mCurrentAnimation->Draw(renderWindow);
}

void cAnimator::FaceLeft()
{
    mCurrentAnimation->SetScale(mFaceLeftScale);
    mIdleAnimation.SetScale(mFaceLeftScale);
    mWallslideAnimation.SetScale(mFaceLeftScale);
}

void cAnimator::FaceRight()
{
    mCurrentAnimation->SetScale(mFaceRightScale);
    mIdleAnimation.SetScale(mFaceRightScale);
    mWallslideAnimation.SetScale(mFaceRightScale);
}

void cAnimator::BeginJump()
{
    mJumpingAnimation.mIsJumpPeakReached = false;
    mCurrentAnimation = &mJumpingAnimation;
}

void cAnimator::JumpPeak()
{
    mJumpingAnimation.mIsJumpPeakReached = true;
}

void cAnimator::StartFall()
{
    mCurrentAnimation = &mJumpingAnimation;
    mJumpingAnimation.mIsJumpPeakReached = true;
}

void cAnimator::EndFall()
{
    mJumpingAnimation.ResetAnimation();
    mJumpingAnimation.mIsJumpPeakReached = false;
    SetRunning(mIsRunning);
}

void cAnimator::SetRunning(bool isRunning)
{
    if (mIsSliding)
    {
        mCurrentAnimation = &mSlidingAnimation;
    }
    else if (isRunning)
    {
        mCurrentAnimation = &mRunningAnimation;
        mIsRunning = true;
    }
    else {
        mCurrentAnimation = &mIdleAnimation;
        mIsRunning = false;
    }
}

void cAnimator::SetSliding(bool isSliding)
{
    mIsSliding = isSliding;
}

void cAnimator::SetWallsliding(bool isWallsliding)
{
    mCurrentAnimation = &mWallslideAnimation;
}
