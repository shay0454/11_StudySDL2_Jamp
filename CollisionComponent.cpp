#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(Actor *owner) : Component(owner),mWidth(0),mHeight(0){}

bool CollisionComponent::Intersect(const CollisionComponent* other) const{
	Vector2 aPos = mOwner->GetPosition();
	Vector2 bPos = other->mOwner->GetPosition();

	float aLeft = aPos.x - mWidth / 2;
	float aRight = aPos.x + mWidth / 2;
	float aUp = aPos.y - mHeight / 2;
	float aDown = aPos.y + mHeight / 2;

	float bLeft = bPos.x - other->mWidth / 2;
	float bRight = bPos.x + other->mWidth / 2;
	float bUp = bPos.y - other->mHeight / 2;
	float bDown = bPos.y + other->mHeight / 2;

	if (aRight < bLeft) return false;
	if (aLeft > bRight) return false;
	if (aUp > bDown) return false;
	if (aDown < bUp) return false;

	return true;
}

//void CheckHit() {
//	if(Intersect())
//	mTextComp->SetText("Hit");
//
//}