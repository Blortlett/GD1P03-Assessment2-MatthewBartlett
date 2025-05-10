#include "cToolButtonKeyObject.h"

cToolButtonKeyObject::cToolButtonKeyObject(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{

}

cToolButtonKeyObject::~cToolButtonKeyObject()
{
}

void cToolButtonKeyObject::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_LevelKey);
}