#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cToolButtonEnemyMine : public cButtonUI
{
public:
    cToolButtonEnemyMine(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cToolButtonEnemyMine();
    void OnButtonClick() override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::RectangleShape mUIIcon;
};