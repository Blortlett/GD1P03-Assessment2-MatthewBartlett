#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"
#include "cLevelPlatformsList.h"
#include "cFileInterface.h"

class cNextLevelButtonUI : public cButtonUI
{
private:
	sf::Text mButtonText;

	cLevelPlatformsList& mLevelPlatformList;
	cFileInterface& mFileInterface;

public:
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;

	cNextLevelButtonUI(cLevelPlatformsList& platformList, cFileInterface& fileInterface);
	~cNextLevelButtonUI();
};