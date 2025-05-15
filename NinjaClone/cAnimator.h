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
#pragma once
#include <SFML/Graphics.hpp>
#include "cAnimationRunning.h"
#include "cAnimationJumping.h"
#include "cAnimationIdle.h"
#include "cAnimationSliding.h"
#include "cAnimationWallslide.h"

class cAnimator : cDrawable
{
public:
	cAnimator();
	~cAnimator();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow) override;
	// Directions
	void FaceLeft();
	void FaceRight();
	void BeginJump();
	void JumpPeak();
	void StartFall();
	void EndFall();
	void SetRunning(bool isRunning);
	void SetSliding(bool isSliding);
	void SetWallsliding(bool isWallsliding);
private:
	// Face left or right
	const sf::Vector2f mFaceLeftScale;
	const sf::Vector2f mFaceRightScale;
	// Animation variables
	bool mIsRunning = false;
	bool mIsSliding = false;
	// Animations
	cAnimation* mCurrentAnimation;
	cAnimationRunning mRunningAnimation;
	cAnimationJumping mJumpingAnimation;
	cAnimationIdle mIdleAnimation;
	cAnimationSliding mSlidingAnimation;
	cAnimationWallslide mWallslideAnimation;
};