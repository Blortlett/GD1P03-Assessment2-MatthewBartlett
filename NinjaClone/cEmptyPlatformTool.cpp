#include "cEmptyPlatformTool.h"

cEmptyPlatformTool::cEmptyPlatformTool()
{
}

cEmptyPlatformTool::~cEmptyPlatformTool()
{
}

void cEmptyPlatformTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos)
{
}

void cEmptyPlatformTool::DrawToolToScreen(sf::RenderWindow& window)
{
}

cPlatformRect* cEmptyPlatformTool::CompleteUseTool()
{
	return nullptr;
}

void cEmptyPlatformTool::UseTool(sf::Vector2f& mousePos)
{
}
