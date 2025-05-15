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
#pragma once
#include "cAnimation.h"

class cKeyAnimation : public cAnimation
{
public:
	cKeyAnimation(sf::Vector2f position);
	~cKeyAnimation();
	void AnimateKey(float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow) override;
private:
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) {} // Blank beacause I'm time pressured on my janky arc
};