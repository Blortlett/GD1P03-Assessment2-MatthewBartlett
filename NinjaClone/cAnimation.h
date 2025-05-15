/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimation]
Description : [The cAnimation class is the base class all playable animations classes inherit from]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cDrawable.h"
#include <string>

class cAnimation : public cDrawable
{
public:
	void LoadSpriteSheet(std::string filePath);
	virtual void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) = 0;
	void SetScale(sf::Vector2f scale);
protected:
	// Time Variables
	float mAnimationTime;
	float mFrameDuration;
	// Image Variables
	sf::Vector2u mCurrentFrame;
	sf::Vector2u mTotalFrames;
	sf::Vector2i mFrameSize;
	sf::Texture mTexture;
	sf::Sprite* mSprite;
	sf::IntRect mSpriteRect;
	// Variables to edit outside of class
	sf::Vector2f mScale;
};