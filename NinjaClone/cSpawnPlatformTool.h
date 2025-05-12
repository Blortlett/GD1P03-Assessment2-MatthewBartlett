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