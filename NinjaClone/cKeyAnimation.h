#pragma once
#include "cAnimation.h"

class cKeyAnimation : public cAnimation
{
public:
	cKeyAnimation(sf::Vector2f position);
	~cKeyAnimation();
	void AnimateKey(float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow) override;
private:
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) {} // Blank beacause I'm time pressured on my janky arc
};