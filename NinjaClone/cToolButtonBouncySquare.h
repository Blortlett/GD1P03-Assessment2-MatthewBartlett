/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cToolButtonBouncySquare]
Description : [cToolButtonBouncySquare when instantiated allows the player to click a button to select the bouncy square tool in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cToolButtonBouncySquare : public cButtonUI
{
public:
    cToolButtonBouncySquare(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cToolButtonBouncySquare();
    void OnButtonClick() override;
    void Draw(sf::RenderWindow& window) override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::RectangleShape mUIIcon;
};