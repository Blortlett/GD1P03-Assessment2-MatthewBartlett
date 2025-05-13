#include "cPlatformLevelStart.h"

cPlatformLevelStart::cPlatformLevelStart(sf::Vector2f position)
	: cPlatformRect(sf::FloatRect(position, sf::Vector2f(80.0f, 20.0f)))
{
	sf::Vector2f spawnPos = position;
	spawnPos.y += 40.f;
	mSpawnPoint = spawnPos;
	mBody.setPosition(position);
	mBody.setSize(mSize);
	sf::Vector2f origin = sf::Vector2f(mSize / 2.0f); // origin = bottom center
	mBody.setOrigin(origin);
	mBody.setFillColor(sf::Color::Green);
}

sf::Vector2f cPlatformLevelStart::GetSpawnPoint()
{
	return mSpawnPoint;
}

sf::Vector2f cPlatformLevelStart::GetPosition()
{
	return mPosition;
}