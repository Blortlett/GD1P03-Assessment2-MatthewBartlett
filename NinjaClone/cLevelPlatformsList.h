#pragma once
#include "cPlatformRect.h"
#include "cLevelExit.h"
#include "cPlayerCharacter.h"
#include <vector>
#include <SFML/Graphics.hpp>

//class cFileInterface;

class cLevelPlatformsList
{
	friend class cFileInterface;
public:
	cLevelPlatformsList();
	~cLevelPlatformsList();
	void AddPlatform(cPlatformRect* platform);
	void AddLevelExit(cLevelExit* levelExit);
	void DrawPlatforms(sf::RenderWindow& window);
	void CheckCollisions(cPlayerCharacter& playerCharacter);
	void ClearList();
private:
	cLevelExit* mLevelExit;
	std::vector<cPlatformRect*> mPlatformList;
	sf::Vector2f mCollisionDirection;
};