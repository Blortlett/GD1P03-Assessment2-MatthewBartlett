/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cSpawnPlatformTool]
Description : [Spawn platform tool allows placing spawnpoints in a level structure]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cPlatformLevelStart.h"
#include "cBaseDrawTool.h"
#include "cLevelPlatformsList.h"

class cSpawnPlatformTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(80, 20);
	cLevelPlatformsList& mLevelPlatformsList;
public:
	cSpawnPlatformTool(cLevelPlatformsList& levelPlatformList);
	~cSpawnPlatformTool() {}
	void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) override;
	void DrawToolToScreen(sf::RenderWindow& window) override;
	cPlatformRect* CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};