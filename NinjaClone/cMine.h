/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cMine]
Description : [This class provides a mine enemy for the player to avoid.]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cApplicationManager.h"
#include "cBoxCollider.h"
#include "cDebugWidget.h"
#include "cCharacter.h"
#include "cAudioPlayer.h"

class cMine
{
private:
	sf::Sprite mSprite;
	sf::Vector2f mPosition;
	cBoxCollider mCollider;
	cDebugWidget mDebugWidget;
	
public:
	cMine(sf::Vector2f position);
	~cMine();

	void Update();
	void Draw(sf::RenderWindow& window);
	bool CheckCollisionWithPlayer(cCharacter& character);

	sf::Vector2f GetPosition() { return mPosition; }
};