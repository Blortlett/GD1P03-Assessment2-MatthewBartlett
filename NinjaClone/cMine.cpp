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
