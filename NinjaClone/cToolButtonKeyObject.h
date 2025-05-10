#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cToolButtonKeyObject : public cButtonUI
{
public:
    cToolButtonKeyObject(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cToolButtonKeyObject();
    void OnButtonClick() override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::RectangleShape mUIIcon;
};