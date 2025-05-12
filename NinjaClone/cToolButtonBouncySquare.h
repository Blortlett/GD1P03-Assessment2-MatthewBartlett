#pragma once
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