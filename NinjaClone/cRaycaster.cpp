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
#include "cRaycaster.h"

cRaycaster::RayHit cRaycaster::CastRay(sf::Vector2f startPos, RayDirection direction, float maxDistance)
{
    RayHit hit = { false, sf::Vector2f(0.f, 0.f), 0.f };

    sf::Vector2f rayDir(0.f, 0.f);
    switch (direction) {
    case RayDirection::Up:    rayDir = sf::Vector2f(0.f, -1.f); break;
    case RayDirection::Down:  rayDir = sf::Vector2f(0.f, 1.f); break;
    case RayDirection::Left:  rayDir = sf::Vector2f(-1.f, 0.f); break;
    case RayDirection::Right: rayDir = sf::Vector2f(1.f, 0.f); break;
    }

    // Step size for raycasting
    const float stepSize = 16.f;
    float distance = 0.f;
    sf::Vector2f currentPos = startPos;

    // Cast ray until hitting a wall or until maxDistance
    while (distance < maxDistance) {
        currentPos += rayDir * stepSize;
        distance += stepSize;

        if (CheckCollision(currentPos)) {
            hit.hit = true;
            hit.hitPos = currentPos;
            hit.distance = distance;
            break;
        }
    }

    return hit;
}

bool cRaycaster::CheckCollision(sf::Vector2f position) const
{
    // Check if position intersects a platform
    // Return true if position is inside a wall
    return false;
}