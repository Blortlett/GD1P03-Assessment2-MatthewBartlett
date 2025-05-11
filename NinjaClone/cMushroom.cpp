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
