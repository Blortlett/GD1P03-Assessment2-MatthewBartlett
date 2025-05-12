#include "cToolButtonSpawnPoint.h"

cToolButtonSpawnPoint::cToolButtonSpawnPoint(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{
	mUIIcon.setFillColor(sf::Color::Green);
	mUIIcon.setSize(sf::Vector2f(12, 8));
	mUIIcon.setPosition(position);
	mUIIcon.setOrigin(mUIIcon.getSize() / 2.f);
}

cToolButtonSpawnPoint::~cToolButtonSpawnPoint()
{
}

void cToolButtonSpawnPoint::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_SpawnPoint);
}

void cToolButtonSpawnPoint::Draw(sf::RenderWindow& window)
{
	window.draw(mButtonShape);
	window.draw(mUIIcon);
}