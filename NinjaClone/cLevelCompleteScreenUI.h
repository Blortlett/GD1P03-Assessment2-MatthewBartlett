#pragma once
#include "cApplicationManager.h"

class cLevelCompleteScreenUI
{
private:
	sf::RenderWindow& mRenderWindow;
	sf::Text mLevelCompleteText;

	bool mIsActive = false;

public:
	cLevelCompleteScreenUI(sf::RenderWindow& renderWindow);
	~cLevelCompleteScreenUI();

	void Update();
};