/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cRectPlatformToolButton]
Description : [cRectPlatformToolButton when instantiated allows the player to click a button to select the RectPlatform tool in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cRectPlatformToolButton.h"

cRectPlatformToolButton::cRectPlatformToolButton(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{
	mUIIcon.setFillColor(sf::Color::Blue);
	mUIIcon.setSize(sf::Vector2f(14, 14));
	mUIIcon.setPosition(position);
	mUIIcon.setOrigin(mUIIcon.getSize() / 2.f);
}

cRectPlatformToolButton::~cRectPlatformToolButton()
{
}

void cRectPlatformToolButton::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_Rect);
}

void cRectPlatformToolButton::Draw(sf::RenderWindow& window)
{
	window.draw(mButtonShape);
	window.draw(mUIIcon);
}
