#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"
#include "cGameManager.h"
#include "cFileInterface.h"

class cMainMenu;

class cLevelEditorButtonUI : public cButtonUI
{
public:
	cLevelEditorButtonUI(sf::Vector2f position, sf::Vector2f size, cGameManager& gameManager, cFileInterface& fileInterface);
	~cLevelEditorButtonUI();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cGameManager& mGameManager;
	cFileInterface& mFileInterface;
	sf::Font mBodyFont;
	sf::Text mText;
};