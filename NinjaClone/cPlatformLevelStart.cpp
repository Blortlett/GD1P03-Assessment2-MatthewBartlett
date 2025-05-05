#include "cPlatformLevelStart.h"

cPlatformLevelStart::cPlatformLevelStart(sf::Vector2f position)
	: cPlatformRect(sf::FloatRect(position, sf::Vector2f(80.0f, 20.0f)))
{
	mSpawnPoint.x = position.y - mSize.y / 2;
	mBody.setPosition(position);
	mBody.setSize(mSize);
	sf::Vector2f origin = sf::Vector2f(mSize / 2.0f); // origin = bottom center
	mBody.setOrigin(origin);
	mBody.setFillColor(sf::Color::Green);
}
