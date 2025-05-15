/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBouncySquare]
Description : [This class provides a bouncy platform the player jump on to get a jump boost and launch high in the air]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cBoxCollider.h"
#include "cApplicationManager.h"
#include "cPlayerCharacter.h"
#include "cDebugWidget.h"

class cBouncySquare
{
private:
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity = { 0, 0 };
	sf::Vector2f mSize = { 24, 24 };
	cBoxCollider mCollider;
	sf::RectangleShape mRectShape;
	cDebugWidget mDebugWidget;
public:
	cBouncySquare(sf::Vector2f position);
	~cBouncySquare();

	bool CheckCollideWithPlayer(cPlayerCharacter& playerCharacter);
	bool CheckCollideWithPoint(sf::Vector2f point);

	void Update(float _DeltaSeconds);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition();
};