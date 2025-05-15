/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cDrawable]
Description : [This class is useless, I added it at the start and I'm too scared / ran out of time to get rid off it. It's useless but a little coupled to things that inherit from it]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cDrawable
{
public:
	cDrawable() {}
	~cDrawable() {}
	virtual void Draw(sf::RenderWindow& renderWindow) = 0;
private:

};