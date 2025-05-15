/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBouncySquareTool]
Description : [cBouncySquareTool allows placing bouncy squares in a level structure]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cBouncySquare.h"
#include "cBaseDrawTool.h"
#include "cLevelPlatformsList.h"

class cBouncySquareTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(24, 24);
	cLevelPlatformsList& mLevelPlatformsList;
public:
	cBouncySquareTool(cLevelPlatformsList& levelPlatformList);
	~cBouncySquareTool() {}

	void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) override;
	void DrawToolToScreen(sf::RenderWindow& window) override;
	cPlatformRect* CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};