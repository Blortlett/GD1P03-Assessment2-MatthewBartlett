/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlatformLevelStart]
Description : [This base class will be inherited by any game objects to give it members such as sprites and position. Useful enough for me to not want to delete]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include "cDrawable.h"

class cGameObject : public cDrawable
{
public:
protected:
	// Position
	sf::Vector2f mPosition;
	// Graphics
	sf::Texture mTexture;// Create texture from above
	sf::Sprite* mSprite; // create sprite from above
};