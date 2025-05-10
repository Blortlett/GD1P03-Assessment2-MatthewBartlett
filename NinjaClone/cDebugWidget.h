#pragma once
#include "cBoxCollider.h"
#include <SFML/Graphics.hpp>

class cDebugWidget
{
private:
	// widget pos
	sf::Vector2f mWidgetPosition;

	// Collider reference
	cBoxCollider& mBoxCollider;

	// Shape for drawing collider
	sf::RectangleShape mColliderGraphic;

public:
	cDebugWidget(cBoxCollider& boxCollider);
	~cDebugWidget();

	void UpdateWidget();
	void DrawWidget(sf::RenderWindow& window);
};