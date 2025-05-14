#pragma once
#include "cPlatformRect.h"
#include "cApplicationManager.h"
#include <SFML/Graphics.hpp>

class cPlatformLevelStart
{
private:
	sf::Vector2f mPosition;
	sf::RectangleShape mBody;
	sf::Vector2f mSize = sf::Vector2f(80.0f, 20.0f);
	sf::Vector2f mSpawnPoint;
public:
	cPlatformLevelStart(sf::Vector2f position);
	~cPlatformLevelStart() {}

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetSpawnPoint();
	sf::Vector2f GetPosition();
};