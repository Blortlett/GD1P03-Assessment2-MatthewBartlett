#include "cLevelPlatformsList.h"

cLevelPlatformsList::cLevelPlatformsList()
{
	mLevelExit = new cLevelExit(sf::Vector2f(-500, -500));
}

cLevelPlatformsList::~cLevelPlatformsList()
{
	ClearList();
	delete mLevelExit;
	mLevelExit = nullptr;
}

void cLevelPlatformsList::AddPlatform(cPlatformRect* platform)
{
	if (!platform) return; // function sometimes has null passed in, handle it here
	std::cout << "Added platform to list" << std::endl;
	mPlatformList.push_back(platform);
}

void cLevelPlatformsList::AddLevelExit(cLevelExit* levelExit)
{
	if (mLevelExit)
	{
		delete mLevelExit;
	}
	mLevelExit = levelExit;
}

void cLevelPlatformsList::DrawPlatforms(sf::RenderWindow& window)
{
	for (size_t i = 0; i < mPlatformList.size(); ++i) {
		mPlatformList[i]->Draw(window);
	}

	mLevelExit->Draw(window);
}

void cLevelPlatformsList::CheckCollisions(cPlayerCharacter& playerCharacter)
{
	bool isColliding = false;
	for (size_t i = 0; i < mPlatformList.size(); ++i) {
		if (mPlatformList[i]->CheckCollideWithPlayer(playerCharacter, mCollisionDirection))
			isColliding = true;
	}

	if (!isColliding)
	{
		playerCharacter.SetUngrounded();
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
