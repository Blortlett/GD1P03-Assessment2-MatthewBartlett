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