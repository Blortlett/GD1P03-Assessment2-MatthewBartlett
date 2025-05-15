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
#pragma once
#include "cAnimation.h"

class cAnimationRunning : public cAnimation
{
public:
	cAnimationRunning();
	~cAnimationRunning();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) override;
	void Draw(sf::RenderWindow& renderWindow) override;
};