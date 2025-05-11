#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cToolButtonEnemyMushroom : public cButtonUI
{
public:
    cToolButtonEnemyMushroom(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cToolButtonEnemyMushroom();
    void OnButtonClick() override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::RectangleShape mUIIcon;
};