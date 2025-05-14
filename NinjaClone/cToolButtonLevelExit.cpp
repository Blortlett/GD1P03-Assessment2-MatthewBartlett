#include "cToolButtonLevelExit.h"

cToolButtonLevelExit::cToolButtonLevelExit(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{
	mIconTexture.loadFromFile("Assets/Sprites/LevelBlocks/LevelExitClosed.png");
	mUIIcon = new sf::Sprite(mIconTexture);
	mUIIcon->setPosition(position);
	mUIIcon->setScale(sf::Vector2f(.25f, .25f));
	mUIIcon->setOrigin(mUIIcon->getLocalBounds().size / 2.0f);
}

cToolButtonLevelExit::~cToolButtonLevelExit()
{
	delete mUIIcon;
}

void cToolButtonLevelExit::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_LevelExit);
}

void cToolButtonLevelExit::Draw(sf::RenderWindow& window)
{
	window.draw(mButtonShape);
	//if (mUIIcon) // dodgy fix
		//window.draw(*mUIIcon);
}
