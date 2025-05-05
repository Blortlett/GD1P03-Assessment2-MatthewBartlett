#pragma once
#include "SFML/Graphics.hpp"
#include "cApplicationManager.h"
#include "cGameObject.h"
#include "cBoxCollider.h"

class cLevelExit : public cGameObject
{
private:
	sf::Vector2f mSize = sf::Vector2f(300, 200);

	sf::Sprite* mDoorClosedSprite;
	sf::Sprite* mDoorOpenSprite;
	cBoxCollider mExitCollider;
public:
	cLevelExit(sf::Vector2f position);
	~cLevelExit() {}

	void Draw(sf::RenderWindow& renderWindow) override;
};