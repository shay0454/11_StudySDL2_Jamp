#include "Ground.h"
#include "AnimSpriteComponent.h"
#include "TextComponent.h"
#include "CollisionComponent.h"

Ground::Ground(class Game* game)
	:Actor(game){
	mAnim = new AnimSpriteComponent(this);
	mAnim->SetDrawOrder(20);
	mAnim->SetTexture(game->GetTexture("Assets/Tiles.png"));
	mTextComp = new TextComponent(this);
	mTextComp->SetColor({ 255,255,255,255 });
	mCollision = new CollisionComponent(this);
	SetGroundType();
	SetType(Type::Ground);
	SetScale(1.5);
	mGroundType = Platform;
}

void Ground::UpdateActor(float deltaTime) {
	Actor::UpdateActor(deltaTime);
	Vector2 pos = GetPosition();
}

void Ground::OnCollision(Actor* other) {
	if (other->GetType() == Type::Player) {
		mTextComp->SetText("Hit");
	}
}

void Ground::SetGroundType(GroundType isGround) {
	mGroundType = isGround;
	if (isGround == GroundType::TheGround) {
		mAnim->SetSourceRect({ 64,32,96,64 });
		mAnim->SetTexWidth(96);
		mAnim->SetTexHeight(64);
		mCollision->SetSize(96, 64);
	}
	else {
		mAnim->SetSourceRect({ 32,32,160,64 });
		mAnim->SetTexWidth(160);
		mAnim->SetTexHeight(64);
		mCollision->SetSize(160, 64);
	}
}

