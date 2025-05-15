/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimationJumping]
Description : [The cAnimationJumping class contains the data and functions necessary to and dispaly and animate the player jumping-state graphics. This should be a member of and called by a cAnimator object]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cAnimation.h"

class cAnimationJumping : public cAnimation
{
public:
	cAnimationJumping();
	~cAnimationJumping();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) override;
	void Draw(sf::RenderWindow& renderWindow) override;
	void ResetAnimation();
	bool mIsJumpPeakReached = false;
private:
};