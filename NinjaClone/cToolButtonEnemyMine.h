/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cToolButtonEnemyMine]
Description : [cToolButtonEnemyMine when instantiated allows the player to click a button to select the EnemyMine tool in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cApplicationManager.h"
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cToolButtonEnemyMine : public cButtonUI
{
public:
    cToolButtonEnemyMine(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cToolButtonEnemyMine();
    void OnButtonClick() override;
    void Draw(sf::RenderWindow& window) override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::Sprite mUIIcon;
};