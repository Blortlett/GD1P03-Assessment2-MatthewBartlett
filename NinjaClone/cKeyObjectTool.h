#pragma once
#include "cKeyObject.h"
#include "cBaseDrawTool.h"
#include "cLevelPlatformsList.h"

class cKeyObjectTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(32, 32);
	cLevelPlatformsList& mLevelPlatformsList;
public:
	cKeyObjectTool(cLevelPlatformsList& levelPlatformList);
	~cKeyObjectTool();
	void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) override;
	void DrawToolToScreen(sf::RenderWindow& window) override;
	cPlatformRect* CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};