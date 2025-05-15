/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cKeyObject]
Description : [This class provides a key for the player to collect before the door will open.]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cKeyObject.h"

cKeyObject::cKeyObject(sf::Vector2f position)
	: mPosition(position)
	, mCollider(sf::FloatRect(position, mKeySize))
	, mKeyAnimation(position)
	, mDebugWidget(mCollider)
{
}

cKeyObject::~cKeyObject()
{

}

void cKeyObject::AnimateKey(float deltaSeconds)
{
	mKeyAnimation.AnimateKey(deltaSeconds);
}

void cKeyObject::Draw(sf::RenderWindow& window)
{
	mKeyAnimation.Draw(window);
	mDebugWidget.DrawWidget(window);
}

bool cKeyObject::CheckCollideWithPlayer(cCharacter& character)
{
	sf::Vector2f collisionDirection = sf::Vector2f(0, 0); // going to ignore this idgaf about it
	if (mCollider.CheckCollision(character.GetCollider(), collisionDirection, 0.0f))
	{
		cAudioPlayer::GetInstance().SFXPlayPickupKey();
		return true;
	}
	return false;
}