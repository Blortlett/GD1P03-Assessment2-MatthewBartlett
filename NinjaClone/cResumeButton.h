/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cResumeButton]
Description : [cResumeButton provides a button for the player to push to resume a paused game]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
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