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
#pragma once
#include "cPlatformRect.h"
#include "cBaseDrawTool.h"

class cEmptyPlatformTool : public cBaseDrawTool
{
public:
	cEmptyPlatformTool();
	~cEmptyPlatformTool();
	void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) override;
	void DrawToolToScreen(sf::RenderWindow& window) override;
	cPlatformRect* CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
private:
	sf::Vector2f mRectSize = sf::Vector2f(0, 0);
};