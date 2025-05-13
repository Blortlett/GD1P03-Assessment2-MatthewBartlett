#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"
#include "cLevelPlatformsList.h"
#include "cFileInterface.h"
class cGameManager;

class cNextLevelButtonUI : public cButtonUI
{
private:
	sf::Text mButtonText;

	cLevelPlatformsList& mLevelPlatformList;
	cFileInterface& mFileInterface;
	cGameManager& mGameManager;

public:
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;

	cNextLevelButtonUI(cLevelPlatformsList& platformList, cFileInterface& fileInterface, cGameManager& gameManager);
	~cNextLevelButtonUI();
};