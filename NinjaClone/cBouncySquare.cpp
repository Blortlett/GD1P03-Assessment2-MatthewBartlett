#include "cBouncySquare.h"

cBouncySquare::cBouncySquare(sf::Vector2f position)
	: mCollider(sf::FloatRect(position, mSize))
	, mPosition(position)
	, mDebugWidget(mCollider)
{
	mRectShape.setPosition(position);
	mRectShape.setSize(mSize);
	mRectShape.setOrigin(mSize / 2.f);

	mRectShape.setFillColor(sf::Color::Black);
	mRectShape.setOutlineColor(sf::Color::White);
	mRectShape.setOutlineThickness(2);
}

cBouncySquare::~cBouncySquare()
{
}

bool cBouncySquare::CheckCollideWithPlayer(cPlayerCharacter& playerCharacter)  // got rid of cPlatformList's mCollisionDirection
{
	sf::Vector2f collisionDirection;
	// Check platform collision with player
	if (mCollider.CheckCollision(playerCharacter.GetCollider(), collisionDirection, 0.0f))
	{
		// If collision, tell player object:
		playerCharacter.OnCollision(collisionDirection);
		return true;
	}
	return false;
}

bool cBouncySquare::CheckCollideWithPoint(sf::Vector2f point)
{ // Delete helper code
	sf::Vector2f newPoint = point;
	newPoint += mCollider.GetHalfSize();
	return mCollider.CheckCollisionPoint(newPoint);
}

void cBouncySquare::Update()
{
	mVelocity = (mCollider.GetPosition() - mPosition) / 2.f;
	mCollider.MoveColliderPosition(mCollider.GetPosition() - mVelocity);
}

void cBouncySquare::Draw(sf::RenderWindow& window)
{
	window.draw(mRectShape);
	if (cApplicationManager::GetInstance().IsDebugModeActive())
	{
		mDebugWidget.DrawWidget(window);
	}
}
