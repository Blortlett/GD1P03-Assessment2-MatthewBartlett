/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevelExit]
Description : [This class provides a finish point to the level]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "SFML/Graphics.hpp"
#include "cApplicationManager.h"
#include "cGameObject.h"
#include "cBoxCollider.h"
#include "cDebugWidget.h"
#include "cPlayerCharacter.h"

class cLevelExit : public cGameObject
{
private:
	sf::Vector2f mSize = sf::Vector2f(30, 20);
	// Sprites
	sf::Sprite* mDoorClosedSprite;
	sf::Sprite* mDoorOpenSprite;
	// Collider
	cBoxCollider mExitCollider;

	// Debug
	cDebugWidget mDebugWidget;
public:
	cLevelExit(sf::Vector2f position);
	~cLevelExit() {}

	// Draw Graphics
	void Draw(sf::RenderWindow& renderWindow) override;

	// Collision check
	bool CheckCollideWithPlayer(cCharacter& character);

	sf::Vector2f GetPosition() { return mPosition; }
};