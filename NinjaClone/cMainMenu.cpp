/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cMainMenu]
Description : [cMainMenu encapsulates the main menu UI to be displayed on load / return to main menu]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cMainMenu.h"

cMainMenu::cMainMenu(sf::RenderWindow& renderWindow, cFileInterface& fileInterface, cGameManager& gameManager, cLevelPlatformsList& platformList, cEditorToolbarUI& editorToolbar)
	: mText(mTitleFont, "NINJA", 7U)
	, mRenderWindow(renderWindow)
	, mFileInterface(fileInterface)
	// Play Button
	, mPlayButtonUI(
		mPlayButtonPosition,
		mButtonSize,
		mFileInterface,
		gameManager
	),
	// Level Edit Button
	mLevelEditorButtonUI(
		mLevelEditorButtonPosition,
		mButtonSize,
		gameManager,
		fileInterface,
		editorToolbar
	)
{
	// get font
	if (!mTitleFont.openFromFile("Assets/Fonts/TypeLightSans-KV84p.otf"))
	{
		std::cerr << "Failed to load title font!" << std::endl;
	}

	// set text
	mText.setFont(mTitleFont);
	mText.setFillColor(sf::Color::Black);
	mText.setCharacterSize(300);
	mText.setPosition(mTitlePosition);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

cMainMenu::~cMainMenu()
{

}

void cMainMenu::Update()
{
	mRenderWindow.draw(mText);
	mPlayButtonUI.Update(mRenderWindow);
	mPlayButtonUI.Draw(mRenderWindow);
	mLevelEditorButtonUI.Update(mRenderWindow);
	mLevelEditorButtonUI.Draw(mRenderWindow);
}

