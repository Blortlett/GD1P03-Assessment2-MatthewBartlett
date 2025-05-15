/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerInput]
Description : [This class has functions to easily read inputs from the player]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>

class cPlayerInput
{
public:
    cPlayerInput();
    bool IsJumpInputPressed() const;
    bool IsMoveLeftInputPressed() const;
    bool IsMoveRightInputPressed() const;
    bool IsLeftClickPressed() const;
    bool IsRightClickPressed() const;
    bool IsPauseButtonPressed() const;
    bool IsDebugButtonPressed() const;
};