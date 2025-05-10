#include "cBaseDrawTool.h"

cBaseDrawTool::cBaseDrawTool() : mShape(nullptr)
{
	delete mShape;
}
cBaseDrawTool::~cBaseDrawTool()
{
	if (mShape)
	{
		delete mShape;
		mShape = nullptr;
	}
}

void cBaseDrawTool::SetShape(sf::Shape* shape)
{
	delete mShape;
	mShape = shape;
}
sf::Shape* cBaseDrawTool::GetShape()
{
	return mShape;
}

void cBaseDrawTool::SetColor(sf::Color color)
{
	mShape->setFillColor(color);
}

void cBaseDrawTool::DrawToolToScreen(sf::RenderWindow& window)
{
	window.draw(*mShape);
}