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
	cBoxCollider& GetCollider() { return mBoxCollider; };
	cBoxCollider GetColliderCopy() { return mBoxCollider; };
	void EditorInitPosition();
};