/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cKeyObject]
Description : [This class provides a key for the player to collect before the door will open.]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cBoxCollider.h"
#include "cKeyAnimation.h"
#include "cDebugWidget.h"
#include "cCharacter.h"
#include "cAudioPlayer.h"


class cKeyObject
{
private:
	sf::Vector2f mPosition;
	sf::Vector2f mKeySize = { 32.0f, 32.0f };
	cBoxCollider mCollider;
	cKeyAnimation mKeyAnimation;

	// Debug
	cDebugWidget mDebugWidget;
public:
	cKeyObject(sf::Vector2f position);
	~cKeyObject();
	
	// Graphics functions
	void AnimateKey(float deltaSeconds);
	void Draw(sf::RenderWindow& window);
	
	// Collision check
	bool CheckCollideWithPlayer(cCharacter& character);

	sf::Vector2f GetPosition() { return mPosition; }
};