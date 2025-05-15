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
#pragma once
#include "cAnimation.h"

class cAnimationWallslide : public cAnimation
{
public:
	cAnimationWallslide();
	~cAnimationWallslide();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) override;
	void Draw(sf::RenderWindow& renderWindow) override;
};