/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cToolButtonKeyObject]
Description : [cToolButtonKeyObject when instantiated allows the player to click a button to select the LevelKey tool in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cToolButtonKeyObject.h"

cToolButtonKeyObject::cToolButtonKeyObject(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
	, mUIIcon(cApplicationManager::GetInstance().mKeyIcon)
{
	

	mUIIcon.setPosition(position);
	mUIIcon.setScale(sf::Vector2f(.7f,.7f));
	mUIIcon.setOrigin(mUIIcon.getLocalBounds().size / 2.0f);

}

cToolButtonKeyObject::~cToolButtonKeyObject()
{
}

void cToolButtonKeyObject::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_LevelKey);
}

void cToolButtonKeyObject::Draw(sf::RenderWindow& window)
{
	window.draw(mButtonShape);
	window.draw(mUIIcon);
}
