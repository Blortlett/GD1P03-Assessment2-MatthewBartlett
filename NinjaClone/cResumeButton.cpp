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
#include "cResumeButton.h"

cResumeButton::cResumeButton()
	: cButtonUI(sf::Vector2f(1366 / 2, (768 / 2) - 30), sf::Vector2f(300, 100))
	, mText(cApplicationManager::GetInstance().GetFont(), "RESUME", 7U)
{
	// Center text
	mText.setPosition(mPosition);
	mText.setCharacterSize(20);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
	mText.setFillColor(sf::Color::Black);
}

cResumeButton::~cResumeButton()
{
}

void cResumeButton::OnButtonClick()
{
	cApplicationManager::GetInstance().SetGameRunning(true);
	cApplicationManager::GetInstance().SetGamePaused(false);
}

void cResumeButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
