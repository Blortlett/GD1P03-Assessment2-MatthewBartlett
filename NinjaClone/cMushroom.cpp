#include "cMushroom.h"

cMushroom::cMushroom(sf::Vector2f position)
	: mPosition(position)
	, mCollider(sf::FloatRect(position, sf::Vector2f(16, 16)))
	, mDebugWidget(mCollider)
	, mSprite(cApplicationManager::GetInstance().mEnemyMushroomSprite)
{
	mSprite.setPosition(position);
	mSprite.setOrigin(mSprite.getLocalBounds().size / 2.0f);
}

cMushroom::~cMushroom()
{

}

void cMushroom::Update()
{

}

void cMushroom::Draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
	mDebugWidget.DrawWidget(window);
}

bool cMushroom::CheckCollisionWithPlayer(cCharacter& character)
{
	sf::Vector2f collisionDirection = sf::Vector2f(0, 0); // going to ignore this idgaf about it
	return mCollider.CheckCollision(character.GetCollider(), collisionDirection, 0.0f);
}
