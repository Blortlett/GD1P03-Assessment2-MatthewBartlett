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