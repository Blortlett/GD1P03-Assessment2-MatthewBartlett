#include "cLevelPlatformsList.h"

cLevelPlatformsList::cLevelPlatformsList()
{
	mLevelExit = new cLevelExit(sf::Vector2f(-500, -500));
	mLevelKey = new cKeyObject(sf::Vector2f(-500, -500));
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
	std::cout << "Added mine to list. List size: " << mMineList.size() << std::endl;
	mMineList.push_back(enemyMine);
}

void cLevelPlatformsList::AddEnemyMushroom(cMushroom* enemyMushroom)
{
	if (!enemyMushroom) return;
	std::cout << "Added mushroom to list" << std::endl;
	mMushroomList.push_back(enemyMushroom);
}

void cLevelPlatformsList::DrawPlatforms(sf::RenderWindow& window, float deltaTime)
{
	for (size_t i = 0; i < mPlatformList.size(); ++i) {
		mPlatformList[i]->Draw(window);
	}

	mLevelExit->Draw(window);

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

	// Draw Mushrooms
	for (size_t i = 0; i < mMushroomList.size(); ++i) {
		mMushroomList[i]->Draw(window);
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
	}

	// If door not unlocked and player not colliding with door
	if (!cApplicationManager::GetInstance().IsDoorUnlocked() && mLevelKey->CheckCollideWithPlayer(playerCharacter))
	{
		// unlock door when player touches key
		cApplicationManager::GetInstance().SetIsDoorUnlocked(true);
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
	if (!CollisionDetected)
	{
		// Check mushrooms
		for (size_t i = 0; i < mMushroomList.size(); ++i) {
			mMushroomList[i]->CheckCollisionWithPlayer(playerCharacter);
		}
	}
	if (CollisionDetected) {
		cApplicationManager::GetInstance().SetIsPlayerDead(true);
	}
}

void cLevelPlatformsList::ClearList()
{
	// Delete each platform object and clear the vector
	for (cPlatformRect* platform : mPlatformList) {
		delete platform;
	}
	mPlatformList.clear();
}
