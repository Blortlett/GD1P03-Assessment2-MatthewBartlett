#pragma once
#include "cBoxCollider.h"
#include "cKeyAnimation.h"
#include "cDebugWidget.h"
#include "cCharacter.h"

class cKeyObject
{
private:
	sf::Vector2f mPosition;
	sf::Vector2f mKeySize = { 32.0f, 32.0f };
	cBoxCollider mCollider;
	cKeyAnimation mKeyAnimation;

	// Debug
	cDebugWidget mDebugWidget;
public:
	cKeyObject(sf::Vector2f position);
	~cKeyObject();
	
	// Graphics functions
	void AnimateKey(float deltaSeconds);
	void Draw(sf::RenderWindow& window);
	void DrawDebug(sf::RenderWindow& window);

	// Collisioncheck
	bool CheckCollideWithPlayer(cCharacter& character);
};