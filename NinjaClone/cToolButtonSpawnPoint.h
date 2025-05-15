/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cToolButtonSpawnPoint]
Description : [cToolButtonSpawnPoint when instantiated allows the player to click a button to select the SpawnPoint tool in the level editor]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cToolButtonSpawnPoint : public cButtonUI
{
public:
    cToolButtonSpawnPoint(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cToolButtonSpawnPoint();
    void OnButtonClick() override;
    void Draw(sf::RenderWindow& window) override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::RectangleShape mUIIcon;
};