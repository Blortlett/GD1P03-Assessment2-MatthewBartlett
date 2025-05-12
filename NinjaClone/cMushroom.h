#pragma once
#include "cApplicationManager.h"
#include "cBoxCollider.h"
#include "cDebugWidget.h"
#include "cCharacter.h"

class cMushroom
{
private:
	sf::Sprite mSprite;
	sf::Vector2f mPosition;
	cBoxCollider mCollider;
	cDebugWidget mDebugWidget;

public:
	cMushroom(sf::Vector2f position);
	~cMushroom();

	void Update();
	void Draw(sf::RenderWindow& window);
	bool CheckCollisionWithPlayer(cCharacter& character);

	sf::Vector2f GetPosition() { return mPosition; }
};