#pragma once
#include "cLevelExit.h"
#include "cBaseDrawTool.h"
#include "cLevelPlatformsList.h"

class cLevelExitTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(300, 200);
	cLevelPlatformsList& mLevelPlatformsList;
public:
	cLevelExitTool(cLevelPlatformsList& levelPlatformList);
	~cLevelExitTool() {}
	void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) override;
	void DrawToolToScreen(sf::RenderWindow& window) override;
	cPlatformRect* CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};