#pragma once
#include "cPlatformRect.h"
#include "cApplicationManager.h"
#include <SFML/Graphics.hpp>

class cPlatformLevelStart : public cPlatformRect  // Bad practice - extending a class that I will be creating objects of
{
private:
	sf::Vector2f mSize = sf::Vector2f(80.0f, 20.0f);
	sf::Vector2f mSpawnPoint;
public:
	cPlatformLevelStart(sf::Vector2f position);
	~cPlatformLevelStart() {}

	sf::Vector2f GetSpawnPoint();
	sf::Vector2f GetPosition();
};