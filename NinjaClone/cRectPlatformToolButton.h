/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cRectPlatformToolButton]
Description : [cRectPlatformToolButton when instantiated allows the player to click a button to select the RectPlatform tool in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cRectPlatformToolButton : public cButtonUI
{
public:
    cRectPlatformToolButton(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cRectPlatformToolButton();
    void OnButtonClick() override;
    void Draw(sf::RenderWindow& window) override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::RectangleShape mUIIcon;
};