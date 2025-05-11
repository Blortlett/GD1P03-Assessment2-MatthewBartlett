#pragma once
#include "cPlatformRect.h"
#include "cLevelExit.h"
#include "cKeyObject.h"
#include "cPlayerCharacter.h"
#include "cMine.h"
#include <vector>
#include <SFML/Graphics.hpp>

class cGameMangager;

class cLevelPlatformsList
{
	friend class cFileInterface;
public:
	cLevelPlatformsList();
	~cLevelPlatformsList();
	void AddPlatform(cPlatformRect* platform);
	void AddLevelKey(cKeyObject* levelKey);
	void AddLevelExit(cLevelExit* levelExit);
	void DrawPlatforms(sf::RenderWindow& window, float deltaTime);
	void CheckCollisions(cPlayerCharacter& playerCharacter);
	void ClearList();
private:
	// Game objects
	cLevelExit* mLevelExit;
	cKeyObject* mLevelKey;
	std::vector<cPlatformRect*> mPlatformList;
	std::vector<cMine*> mMineList;
	sf::Vector2f mCollisionDirection;
};