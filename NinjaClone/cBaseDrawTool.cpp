/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBaseDrawTool]
Description : [This class is inherited by all draw tools. Provides functions to be called by the cEditorDrawTool (the manager class)]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cBaseDrawTool.h"

cBaseDrawTool::cBaseDrawTool() : mShape(nullptr)
{
	delete mShape;
}
cBaseDrawTool::~cBaseDrawTool()
{
	if (mShape)
	{
		// if below is commented on submission... i fucked up here lol   // annoying me
		//delete mShape;
		//mShape = nullptr;
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