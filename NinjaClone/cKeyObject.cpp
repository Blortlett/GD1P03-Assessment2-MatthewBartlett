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
}

void cKeyObject::DrawDebug(sf::RenderWindow& window)
{
	mDebugWidget.UpdateWidget();
	mDebugWidget.DrawWidget(window);
}

bool cKeyObject::CheckCollideWithPlayer(cCharacter& character)
{
	sf::Vector2f collisionDirection = sf::Vector2f(0, 0); // going to ignore this idgaf about it

	return mCollider.CheckCollision(character.GetCollider(), collisionDirection, 0.0f);
}