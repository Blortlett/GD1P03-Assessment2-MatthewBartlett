/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayButtonUI]
Description : [cPlayButtonUI provides a button for the player to push to start the game from the main menu]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cButtonUI.h"
#include "cFileInterface.h"
#include "cApplicationManager.h"
#include "cAudioPlayer.h"
#include "cGameManager.h"


class cMainMenu;

class cPlayButtonUI : public cButtonUI
{
public:
	cPlayButtonUI(sf::Vector2f position, sf::Vector2f size, cFileInterface& fileInterface, cGameManager& gameManager);
	~cPlayButtonUI() = default;
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cFileInterface& mFileInterface;

	sf::Font& mBodyFont;
	sf::Text mText;
	cGameManager& mGameManager;
};