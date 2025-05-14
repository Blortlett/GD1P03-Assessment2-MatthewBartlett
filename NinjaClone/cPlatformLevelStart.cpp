#include "cPlatformLevelStart.h"

cPlatformLevelStart::cPlatformLevelStart(sf::Vector2f position)
	: mPosition(position)
{
	sf::Vector2f spawnPos = position;
	spawnPos.y -= 40.f;
	mSpawnPoint = spawnPos;
	mBody.setPosition(position);
	mBody.setSize(mSize);
	sf::Vector2f origin = sf::Vector2f(mSize / 2.0f); // origin = bottom center
	mBody.setOrigin(origin);
	mBody.setFillColor(sf::Color::Green);
}

void cPlatformLevelStart::Draw(sf::RenderWindow& window)
{
	window.draw(mBody);
}

sf::Vector2f cPlatformLevelStart::GetSpawnPoint()
{
	return mSpawnPoint;
}

sf::Vector2f cPlatformLevelStart::GetPosition()
{
	return mPosition;
}

