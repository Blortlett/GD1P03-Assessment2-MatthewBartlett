#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cToolButtonLevelExit : public cButtonUI
{
public:
    cToolButtonLevelExit(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cToolButtonLevelExit();
    void OnButtonClick() override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::RectangleShape mUIIcon;
};