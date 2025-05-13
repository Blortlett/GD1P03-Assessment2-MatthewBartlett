#include "cLevelPlatformsList.h"

cLevelPlatformsList::cLevelPlatformsList()
{
	mLevelExit = new cLevelExit(sf::Vector2f(-500, -500));
	mLevelKey = new cKeyObject(sf::Vector2f(-500, -500));

	ClearList();
}

cLevelPlatformsList::~cLevelPlatformsList()
{
	ClearList();
	delete mLevelExit;
	mLevelExit = nullptr;

	delete mLevelKey;
	mLevelKey = nullptr;
}

void cLevelPlatformsList::AddPlatform(cPlatformRect* platform)
{
	if (!platform) return; // function sometimes has null passed in, handle it here
	std::cout << "Added platform to list" << std::endl;
	mPlatformList.push_back(platform);
}

void cLevelPlatformsList::AddPlayerSpawn(cPlatformLevelStart* playerSpawn)
{
	if (mPlayerSpawn)
	{
		delete mPlayerSpawn;
	}
	mPlayerSpawn = playerSpawn;
}

void cLevelPlatformsList::AddLevelKey(cKeyObject* levelKey)
{
	if (levelKey)
	{
		delete mLevelKey;
	}
	mLevelKey = levelKey;
}

void cLevelPlatformsList::AddLevelExit(cLevelExit* levelExit)
{
	if (mLevelExit)
	{
		delete mLevelExit;
	}
	mLevelExit = levelExit;
}

void cLevelPlatformsList::AddEnemyMine(cMine* enemyMine)
{
	if (!enemyMine) return;
	mMineList.push_back(enemyMine);
}

void cLevelPlatformsList::AddBouncySquare(cBouncySquare* bouncySquare)
{
	if (!bouncySquare) return;
	mBouncySquareList.push_back(bouncySquare);
}

void cLevelPlatformsList::DrawPlatforms(sf::RenderWindow& window, float deltaTime)
{
	for (size_t i = 0; i < mPlatformList.size(); ++i) {
		mPlatformList[i]->Draw(window);
	}

	for (size_t i = 0; i < mBouncySquareList.size(); ++i) {
		mBouncySquareList[i]->Draw(window);
	}

	if (mPlayerSpawn) {
		mPlayerSpawn->Draw(window);
	}

	if (mLevelExit) {
		mLevelExit->Draw(window);
	}

	if (!cApplicationManager::GetInstance().IsDoorUnlocked())
	{
		mLevelKey->AnimateKey(deltaTime);
		mLevelKey->Draw(window);
	}
}

void cLevelPlatformsList::DrawEnemies(sf::RenderWindow& window, float deltaTime)
{
	// Draw Mines
	for (size_t i = 0; i < mMineList.size(); ++i) {
		mMineList[i]->Draw(window);
	}
}

void cLevelPlatformsList::CheckCollisions(cPlayerCharacter& playerCharacter)
{
	// Check player collision with all level platforms
	bool isColliding = false;
	for (size_t i = 0; i < mPlatformList.size(); ++i) {
		if (mPlatformList[i]->CheckCollideWithPlayer(playerCharacter, mCollisionDirection))
			isColliding = true;
	}

	// Check player collisions with bouncy squares
	for (size_t i = 0; i < mBouncySquareList.size(); ++i) {
		if (mBouncySquareList[i]->CheckCollideWithPlayer(playerCharacter)) // didnt wanna chuck in the same collision direction
			isColliding = true;
		mBouncySquareList[i]->Update();
	}

	// Ensure player is not grounded if touching no platforms
	if (!isColliding)
	{
		playerCharacter.SetUngrounded();
	}

	// Check player collision with game objects
	// If level not complete and door unlocked and player touching door collider
	if (!cApplicationManager::GetInstance().IsLevelComplete() && cApplicationManager::GetInstance().IsDoorUnlocked() && mLevelExit->CheckCollideWithPlayer(playerCharacter))
	{
		// Set level complete
		cApplicationManager::GetInstance().SetIsLevelComplete(true);
		playerCharacter.KillInput();
	}

	// If door not unlocked and player not colliding with door
	if (!cApplicationManager::GetInstance().IsDoorUnlocked() && mLevelKey->CheckCollideWithPlayer(playerCharacter))
	{
		// unlock door when player touches key
		cApplicationManager::GetInstance().SetIsDoorUnlocked(true);
	}
}

void cLevelPlatformsList::TryDeletePlatform(sf::Vector2f pointCollision)
{
	for (size_t i = 0; i < mPlatformList.size(); ++i) {
		if (mPlatformList[i]->CheckCollideWithPoint(pointCollision))
		{
			delete mPlatformList[i];
			mPlatformList.erase(mPlatformList.begin() + i);
		}
	}
}

void cLevelPlatformsList::CheckEnemyCollisions(cPlayerCharacter& playerCharacter)
{
	bool CollisionDetected = false;

	// Check mines
	for (size_t i = 0; i < mMineList.size(); ++i) {
		CollisionDetected = mMineList[i]->CheckCollisionWithPlayer(playerCharacter);
		if (CollisionDetected) break;
	}

	if (CollisionDetected) {
		cApplicationManager::GetInstance().SetIsPlayerDead(true);
	}
}

void cLevelPlatformsList::ClearList()
{
	// Clear Level Exit
	delete mLevelExit;
	mLevelExit = new cLevelExit(sf::Vector2f(-500, -500));
	// Clear Level Key
	delete mLevelKey;
	mLevelKey = new cKeyObject(sf::Vector2f(-500, -500));
	// Clear Level Spawn
	delete mPlayerSpawn;
	mPlayerSpawn = new cPlatformLevelStart(sf::Vector2f(-500, -500));

	// Delete each platform object and clear the vector
	for (cPlatformRect* platform : mPlatformList) {
		delete platform;
	}
	mPlatformList.clear();

	// Delete each bouncy square object and clear the vector
	for (cBouncySquare* bouncySquare : mBouncySquareList) {
		delete bouncySquare;
	}
	mBouncySquareList.clear();

	// Delete each Mine object and clear the vector
	for (cMine* mine : mMineList) {
		delete mine;
	}
	mMineList.clear();
}

sf::Vector2f cLevelPlatformsList::GetPlayerSpawnPos()
{
	if (mPlayerSpawn)
		if (mPlayerSpawn->GetSpawnPoint().x < 0.f && mPlayerSpawn->GetSpawnPoint().y < 0.f)
			return sf::Vector2f(1366, 768) / 2.f; // spawn off screen
		else 
			return mPlayerSpawn->GetSpawnPoint(); // legal spawn, return position
	else
		return sf::Vector2f(1366, 768) / 2.f; // no spawn point
}
