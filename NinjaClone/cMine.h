#pragma once
#include "cApplicationManager.h"
#include "cBoxCollider.h"
#include "cDebugWidget.h"

class cMine
{
private:
	sf::Sprite mSprite;
	sf::Vector2f mPosition;
	cBoxCollider mCollider;
	cDebugWidget mDebugWidget;
	
public:
	cMine(sf::Vector2f position);
	~cMine();

	void Update();
	void Draw(sf::RenderWindow& window);
};