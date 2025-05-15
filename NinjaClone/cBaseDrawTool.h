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
#pragma once
#include "cPlatformRect.h"
#include <SFML/Graphics.hpp>

class cBaseDrawTool
{
public:
	cBaseDrawTool();
	~cBaseDrawTool();
	void SetShape(sf::Shape* shape);
	sf::Shape* GetShape();
	void SetColor(sf::Color color);
	virtual void DrawToolToScreen(sf::RenderWindow& window) = 0;

	virtual void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) = 0;
	virtual void UseTool(sf::Vector2f& mousePos) = 0;
	virtual cPlatformRect* CompleteUseTool() = 0;
protected:
	sf::Shape* mShape;
};