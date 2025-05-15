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
#include "cAnimation.h"
#include <iostream>

void cAnimation::LoadSpriteSheet(std::string filePath)
{
	mFrameDuration = 0.15f;
	mAnimationTime = 0.0f;

	mTexture = sf::Texture(filePath);
	mTexture.setSmooth(true);
	mSprite = new sf::Sprite(mTexture);

	mSprite->setScale(sf::Vector2f(.11f, .11f));
	mSprite->setOrigin(sf::Vector2f((mFrameSize.x / 2), mFrameSize.y));

	mSpriteRect = sf::IntRect(sf::Vector2i(0, 0), mFrameSize);
	mSprite->setTextureRect(mSpriteRect);
}

void cAnimation::SetScale(sf::Vector2f scale)
{
	mScale = scale;
	mSprite->setScale(mScale);
}
