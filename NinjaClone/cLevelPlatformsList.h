/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevelPlatformsList]
Description : [cLevelPlatformsList has a terrible name and stores level data for each level. When loading a new level, this class clears data and reloads new level data to be displayed]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlatformRect.h"
#include "cPlatformLevelStart.h"
#include "cLevelExit.h"
#include "cKeyObject.h"
#include "cPlayerCharacter.h"
#include "cMine.h"
#include "cBouncySquare.h"
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
	void AddBouncySquare(cBouncySquare* bouncySquare);
	void DrawPlatforms(sf::RenderWindow& window, float deltaTime);
	void DrawEnemies(sf::RenderWindow& window, float deltaTime);
	void CheckCollisions(cPlayerCharacter& playerCharacter, float deltaTime);
	void TryDeletePlatform(sf::Vector2f pointCollision);
	void CheckEnemyCollisions(cPlayerCharacter& playerCharacter);
	void ClearList();
	sf::Vector2f GetPlayerSpawnPos();
private:
	// Game objects
	cLevelExit* mLevelExit;
	cKeyObject* mLevelKey;
	cPlatformLevelStart* mPlayerSpawn;
	std::vector<cPlatformRect*> mPlatformList;
	std::vector<cBouncySquare*> mBouncySquareList;
	std::vector<cMine*> mMineList;
	sf::Vector2f mCollisionDirection;
};