/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEnemyMineTool]
Description : [cEnemyMineTool allows placing mines in a level structure]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cMine.h"
#include "cBaseDrawTool.h"
#include "cLevelPlatformsList.h"

class cEnemyMineTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(16, 16);
	cLevelPlatformsList& mLevelPlatformsList;
public:
	cEnemyMineTool(cLevelPlatformsList& levelPlatformList);
	~cEnemyMineTool() {}

	void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) override;
	void DrawToolToScreen(sf::RenderWindow& window) override;
	cPlatformRect* CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};