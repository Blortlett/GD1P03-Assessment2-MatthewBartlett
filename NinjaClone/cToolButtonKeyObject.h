/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cToolButtonKeyObject]
Description : [cToolButtonKeyObject when instantiated allows the player to click a button to select the LevelKey tool in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cToolButtonKeyObject : public cButtonUI
{
public:
    cToolButtonKeyObject(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cToolButtonKeyObject();
    void OnButtonClick() override;
    void Draw(sf::RenderWindow& window) override;
private:
    cEditorDrawTool& mUserDrawTool;

    //Icon
    sf::Sprite mUIIcon;
};