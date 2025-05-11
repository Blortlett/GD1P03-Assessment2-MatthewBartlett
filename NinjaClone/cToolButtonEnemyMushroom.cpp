#include "cToolButtonEnemyMushroom.h"

cToolButtonEnemyMushroom::cToolButtonEnemyMushroom(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{

}

cToolButtonEnemyMushroom::~cToolButtonEnemyMushroom()
{
}

void cToolButtonEnemyMushroom::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_EnemyMushroom);
}