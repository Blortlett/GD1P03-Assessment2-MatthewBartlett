#pragma once
#include "cBoxCollider.h"
#include <SFML/Graphics.hpp>
#include "cApplicationManager.h"

class cDebugWidget
{
private:
	// widget pos
	sf::Vector2f mWidgetPosition;

	// Collider reference
	cBoxCollider& mBoxCollider;

	// Shape for drawing collider
	sf::RectangleShape mColliderGraphic;

	void UpdateWidget();
public:
	cDebugWidget(cBoxCollider& boxCollider);
	~cDebugWidget();

	void DrawWidget(sf::RenderWindow& window);
};