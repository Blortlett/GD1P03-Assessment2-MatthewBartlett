/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cMine]
Description : [This class provides a mine enemy for the player to avoid.]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cMine.h"

cMine::cMine(sf::Vector2f position)
	: mPosition(position)
	, mCollider(sf::FloatRect(position, sf::Vector2f(16, 16)))
	, mDebugWidget(mCollider)
	, mSprite(cApplicationManager::GetInstance().mEnemyMineSprite)
{
	mSprite.setPosition(position);
	mSprite.setOrigin(mSprite.getLocalBounds().size / 2.0f);
}

cMine::~cMine()
{

}

void cMine::Update()
{

}

void cMine::Draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
	mDebugWidget.DrawWidget(window);
}

bool cMine::CheckCollisionWithPlayer(cCharacter& character)
{
	sf::Vector2f collisionDirection = sf::Vector2f(0, 0); // going to ignore this idgaf about it
	if (mCollider.CheckCollision(character.GetCollider(), collisionDirection, 1.0f))
	{
		cAudioPlayer::GetInstance().SFXPlayExplosion();
		return true;
	}
	else
		return false;
}
