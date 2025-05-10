#include "cDebugWidget.h"

cDebugWidget::cDebugWidget(cBoxCollider& boxCollider)
	: mBoxCollider(boxCollider)
{
	mColliderGraphic.setSize(boxCollider.GetBounds().size);
	mColliderGraphic.setPosition(boxCollider.GetPosition());
	mColliderGraphic.setFillColor(sf::Color::Transparent);
	mColliderGraphic.setOutlineColor(sf::Color::Red);
	mColliderGraphic.setOutlineThickness(2);
}

cDebugWidget::~cDebugWidget()
{
}

void cDebugWidget::UpdateWidget()
{
}

void cDebugWidget::DrawWidget(sf::RenderWindow& window)
{
	window.draw(mColliderGraphic);
}
