#include "cSaveButton.h"

cSaveButton::cSaveButton(sf::Vector2f position, sf::Vector2f size, cFileInterface& _userFileInterface, cLevelPlatformsList& platformList)
	: cButtonUI(position, size)
	, mFileInterface(_userFileInterface)
	, mPlatformList(platformList)
	, mUIIcon(cApplicationManager::GetInstance().mSaveIcon)
{
	// set position
	mUIIcon.setOrigin(mUIIcon.getLocalBounds().size / 2.0f);
	mUIIcon.setPosition(position);
}

cSaveButton::~cSaveButton()
{
}

void cSaveButton::OnButtonClick()
{
	// Save the platform list
	mFileInterface.SaveLevelDialog();
}

void cSaveButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Update(window);
	// Draw Button to screen
	cButtonUI::Draw(window);
	window.draw(mUIIcon);
}