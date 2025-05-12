#pragma once
#include "cPlatformRect.h"
#include "cPlatformLevelStart.h"
#include "cLevelExit.h"
#include "cKeyObject.h"
#include "cPlayerCharacter.h"
#include "cMine.h"
#include "cMushroom.h"
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
	void AddPlayerSpawn(cPlatformLevelStart* playerSpawn);
	void AddLevelKey(cKeyObject* levelKey);
	void AddLevelExit(cLevelExit* levelExit);
	void AddEnemyMine(cMine* enemyMine);
	void AddEnemyMushroom(cMushroom* enemyMushroom);
	void DrawPlatforms(sf::RenderWindow& window, float deltaTime);
	void DrawEnemies(sf::RenderWindow& window, float deltaTime);
	void CheckCollisions(cPlayerCharacter& playerCharacter);
	void CheckEnemyCollisions(cPlayerCharacter& playerCharacter);
	void ClearList();
	sf::Vector2f GetPlayerSpawnPos();
private:
	// Game objects
	cLevelExit* mLevelExit;
	cKeyObject* mLevelKey;
	cPlatformLevelStart* mPlayerSpawn;
	std::vector<cPlatformRect*> mPlatformList;
	std::vector<cMine*> mMineList;
	std::vector<cMushroom*> mMushroomList;
	sf::Vector2f mCollisionDirection;
};