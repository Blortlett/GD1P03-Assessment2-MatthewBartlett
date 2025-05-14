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