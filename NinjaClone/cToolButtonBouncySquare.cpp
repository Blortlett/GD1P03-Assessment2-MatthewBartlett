#include "cToolButtonBouncySquare.h"

cToolButtonBouncySquare::cToolButtonBouncySquare(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{
	mUIIcon.setPosition(position);
	sf::Vector2f iconSize;
	iconSize.x = mSize.x - 16;
	iconSize.y = mSize.y - 16;
	mUIIcon.setSize(iconSize);
	mUIIcon.setOrigin(iconSize / 2.f);

	mUIIcon.setFillColor(sf::Color::Black);
	mUIIcon.setOutlineColor(sf::Color::White);
	mUIIcon.setOutlineThickness(2);
}

cToolButtonBouncySquare::~cToolButtonBouncySquare()
{
}

void cToolButtonBouncySquare::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_BouncySquare);
}

void cToolButtonBouncySquare::Draw(sf::RenderWindow& window)
{
	window.draw(mButtonShape);
	window.draw(mUIIcon);
}
