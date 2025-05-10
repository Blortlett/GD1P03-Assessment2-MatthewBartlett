#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"

class cResumeButton : public cButtonUI
{
private:
	sf::Text mText;
public:
	cResumeButton();
	~cResumeButton();

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
};