/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cToolButtonLevelExit]
Description : [cToolButtonLevelExit when instantiated allows the player to click a button to select the LevelExit tool in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cApplicationManager.h"
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cToolButtonLevelExit : public cButtonUI
{
public:
    cToolButtonLevelExit(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cToolButtonLevelExit();
    void OnButtonClick() override;
    void Draw(sf::RenderWindow& window) override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::Sprite mUIIcon;
};