#include "cToolButtonEnemyMine.h"

cToolButtonEnemyMine::cToolButtonEnemyMine(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{

}

cToolButtonEnemyMine::~cToolButtonEnemyMine()
{
}

void cToolButtonEnemyMine::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_EnemyMine);
}