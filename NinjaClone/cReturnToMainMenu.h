#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"
#include "cLevelPlatformsList.h"
#include "cAudioPlayer.h"

class cReturnToMainMenu : public cButtonUI
{
private:
	sf::Text mText;
	cLevelPlatformsList& mPlatformsList;
public:
	cReturnToMainMenu(cLevelPlatformsList& platformsList);
	~cReturnToMainMenu();

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
};