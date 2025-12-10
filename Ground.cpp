#include "Ground.h"
#include "AnimSpriteComponent.h"
#include "TextComponent.h"
#include "CollisionComponent.h"

Ground::Ground(class Game* game)
	:Actor(game){
	mAnim = new AnimSpriteComponent(this);
	mAnim->SetSourceRect({ 32,32,160,64 });
	mAnim->SetTexture(game->GetTexture("Assets/Tiles.png"));
	mAnim->SetTexHeight(64);
	mAnim->SetTexWidth(160);
	mTextComp = new TextComponent(this);
	mTextComp->SetColor({ 255,255,255,255 });
	SetScale(2.0f);
	mCollision = new CollisionComponent(this);
	mCollision->SetSize(160, 64);

	SetType(GroundType);
}

void Ground::UpdateActor(float deltaTime) {
	Actor::UpdateActor(deltaTime);
	Vector2 pos = GetPosition();
}

void Ground::OnCollision(Actor* other) {
	mTextComp->SetText("Collision with Ground!");
}
