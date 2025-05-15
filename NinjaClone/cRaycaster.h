/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cRaycaster]
Description : [This class I tried to play around with raycasting and gave up... for now >:) ]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "SFML/Graphics.hpp"
#include "cBoxCollider.h"

class cRaycaster {
public:
    cRaycaster() = default;
    ~cRaycaster() = default;

    enum class RayDirection { Up, Down, Left, Right };

    struct RayHit {
        bool hit;                   // True if hit a wall
        sf::Vector2f hitPos;        // Coordinate of the hit
        float distance;             // Distance to the hit
    };

    // Cast a ray in direction from startPos
    RayHit CastRay(sf::Vector2f startPos, RayDirection direction, float maxDistance = 1000.f);

private:
    // Function to check if a position is a wall (to be implemented based on your game)
    bool CheckCollision(sf::Vector2f position) const;
};