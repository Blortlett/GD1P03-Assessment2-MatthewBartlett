#include "cToolButtonSpawnPoint.h"

cToolButtonSpawnPoint::cToolButtonSpawnPoint(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{

}

cToolButtonSpawnPoint::~cToolButtonSpawnPoint()
{
}

void cToolButtonSpawnPoint::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_SpawnPoint);
}