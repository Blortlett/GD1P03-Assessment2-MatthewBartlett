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