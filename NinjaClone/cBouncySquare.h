#pragma once
#include "cBoxCollider.h"
#include "cApplicationManager.h"
#include "cPlayerCharacter.h"
#include "cDebugWidget.h"

class cBouncySquare
{
private:
	sf::Vector2f mPosition;
	sf::Vector2f mSize = { 24, 24 };
	cBoxCollider mCollider;
	sf::RectangleShape mRectShape;
	cDebugWidget mDebugWidget;
public:
	cBouncySquare(sf::Vector2f position);
	~cBouncySquare();

	bool CheckCollideWithPlayer(cPlayerCharacter& playerCharacter, sf::Vector2f& collisionDirection);
	bool CheckCollideWithPoint(sf::Vector2f point);

	void Update();
	void Draw(sf::RenderWindow& window);
};