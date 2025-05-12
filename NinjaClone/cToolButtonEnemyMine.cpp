#include "cToolButtonEnemyMine.h"

cToolButtonEnemyMine::cToolButtonEnemyMine(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
	, mUIIcon(cApplicationManager::GetInstance().mEnemyMineSprite)
{
	mUIIcon.setPosition(position);
	mUIIcon.setOrigin(mUIIcon.getLocalBounds().size / 2.0f);
}

cToolButtonEnemyMine::~cToolButtonEnemyMine()
{
}

void cToolButtonEnemyMine::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_EnemyMine);
}

void cToolButtonEnemyMine::Draw(sf::RenderWindow& window)
{
	window.draw(mButtonShape);
	window.draw(mUIIcon);
}
