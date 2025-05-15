/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEmptyPlatformTool]
Description : [cEmptyPlatformTool allows having an empty mouse in the editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cEmptyPlatformTool.h"

cEmptyPlatformTool::cEmptyPlatformTool()
{
}

cEmptyPlatformTool::~cEmptyPlatformTool()
{
}

void cEmptyPlatformTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos)
{
}

void cEmptyPlatformTool::DrawToolToScreen(sf::RenderWindow& window)
{
}

cPlatformRect* cEmptyPlatformTool::CompleteUseTool()
{
	return nullptr;
}

void cEmptyPlatformTool::UseTool(sf::Vector2f& mousePos)
{
}
