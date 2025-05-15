/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cRectPlatformTool]
Description : [cRectPlatformTool allows placing ground/wall platforms in a level structure]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlatformRect.h"
#include "cBaseDrawTool.h"

class cRectPlatformTool : public cBaseDrawTool
{
public:
	cRectPlatformTool();
	~cRectPlatformTool();
	void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) override;
	void DrawToolToScreen(sf::RenderWindow& window) override;
	cPlatformRect* CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
private:
	sf::Vector2f mRectSize = sf::Vector2f(24, 24);
};