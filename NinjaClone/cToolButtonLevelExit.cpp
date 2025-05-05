#include "cToolButtonLevelExit.h"

cToolButtonLevelExit::cToolButtonLevelExit(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{

}

cToolButtonLevelExit::~cToolButtonLevelExit()
{
}

void cToolButtonLevelExit::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_LevelExit);
}