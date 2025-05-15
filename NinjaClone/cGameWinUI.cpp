/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cGameWinUI]
Description : [cGameWinUI encapsulates the game win UI to be displayed on game complete]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cGameWinUI.h"

cGameWinUI::cGameWinUI(sf::RenderWindow& renderWindow, cLevelPlatformsList& platformList, cEditorToolbarUI editorToolbar)
	: mRenderWindow(renderWindow)
	, mReturnToMenuButton(platformList, editorToolbar)
	, mText(cApplicationManager::GetInstance().GetFont(), "YOU WIN!", 10U)
{
	mText.setFillColor(sf::Color::Black);
	mText.setCharacterSize(260);
	mText.setPosition(mTitlePosition);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cGameWinUI::Update()
{
	if (cApplicationManager::GetInstance().mIsGameComplete)
	{
		mRenderWindow.draw(mText);
		mReturnToMenuButton.Update(mRenderWindow);
		mReturnToMenuButton.Draw(mRenderWindow);
	}
}
