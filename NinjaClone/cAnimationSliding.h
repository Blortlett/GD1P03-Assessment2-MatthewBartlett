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
#pragma once
#include "cAnimation.h"

class cAnimationSliding : public cAnimation
{
public:
	cAnimationSliding();
	~cAnimationSliding();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) override;
	void Draw(sf::RenderWindow& renderWindow) override;
};