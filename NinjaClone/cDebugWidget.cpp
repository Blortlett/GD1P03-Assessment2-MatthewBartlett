#include "cDebugWidget.h"

cDebugWidget::cDebugWidget(cBoxCollider& boxCollider)
	: mBoxCollider(boxCollider)
{
	mColliderGraphic.setSize(boxCollider.GetBounds().size);
	mColliderGraphic.setPosition(boxCollider.GetPosition());
	mColliderGraphic.setOrigin(boxCollider.GetBounds().size / 2.0f);
	mColliderGraphic.setFillColor(sf::Color::Transparent);
	mColliderGraphic.setOutlineColor(sf::Color::Red);
	mColliderGraphic.setOutlineThickness(2);
}

cDebugWidget::~cDebugWidget()
{
}

void cDebugWidget::UpdateWidget()
{
	mColliderGraphic.setSize(mBoxCollider.GetBounds().size);
	mColliderGraphic.setPosition(mBoxCollider.GetPosition());
}

void cDebugWidget::DrawWidget(sf::RenderWindow& window)
{
	if (!cApplicationManager::GetInstance().IsDebugModeActive()) return;
	UpdateWidget();
	window.draw(mColliderGraphic);
}
