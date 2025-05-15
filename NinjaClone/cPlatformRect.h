/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlatformLevelStart]
Description : [This class provides the basic platform piece used as ground/walls in all levels]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cBoxCollider.h"
#include "cGameObject.h"
#include "cCharacter.h"

class cPlatformRect : public cGameObject
{
protected:
	sf::RectangleShape mBody;
	cBoxCollider mBoxCollider;
public:
	cPlatformRect(sf::FloatRect bounds);
	~cPlatformRect();

	void Draw(sf::RenderWindow& window);
	bool CheckCollideWithPlayer(cCharacter& character, sf::Vector2f& collisionDirection);
	bool CheckCollideWithPoint(sf::Vector2f point);
	cBoxCollider& GetCollider() { return mBoxCollider; };
	cBoxCollider GetColliderCopy() { return mBoxCollider; };
	void EditorInitPosition();
};