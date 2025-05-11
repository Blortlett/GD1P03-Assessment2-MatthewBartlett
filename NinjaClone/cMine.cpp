#include "cMine.h"

cMine::cMine(sf::Vector2f position)
	: mPosition(position)
	, mCollider(sf::FloatRect(position, sf::Vector2f(16, 16)))
	, mDebugWidget(mCollider)
{
	mSprite = new sf::Sprite(cApplicationManager::GetInstance().GetMineTexture());
}

cMine::~cMine()
{
	delete mSprite;
	mSprite = nullptr;
}

void cMine::Update()
{

}

void cMine::Draw(sf::RenderWindow& window)
{
	window.draw(*mSprite);
	mDebugWidget.DrawWidget(window);
}
