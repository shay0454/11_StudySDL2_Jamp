#include "Player.h"
#include "Game.h"
#include "AnimSpriteComponent.h"
#include "TextComponent.h"
#include "CollisionComponent.h"
#include "Ground.h"
Player::Player(Game *game) : Actor(game),mRightSpeed(0),mDownSpeed(0) {
	mAnim = new AnimSpriteComponent(this);
	//텍스처의 일부만 랜더링하기 위한 부분 설정
	mAnim->SetSourceRect({ 0,0,PlayerWidth,PlayerHeight });

	mAnimations[Idle] = {
		game->GetTexture("Assets/Character01.png")
	};
	mAnimations[Move] = {
		game->GetTexture("Assets/Character02.png"),
		game->GetTexture("Assets/Character03.png"),
		game->GetTexture("Assets/Character04.png"),
		game->GetTexture("Assets/Character05.png"),
		game->GetTexture("Assets/Character06.png"),
	};
	mAnimations[Jamp] = {
		game->GetTexture("Assets/Character07.png"),
		game->GetTexture("Assets/Character08.png"),
		game->GetTexture("Assets/Character09.png"),
		game->GetTexture("Assets/Character10.png"),
		game->GetTexture("Assets/Character11.png"),
		game->GetTexture("Assets/Character12.png"),
		game->GetTexture("Assets/Character13.png"),
		game->GetTexture("Assets/Character14.png"),
		game->GetTexture("Assets/Character15.png")
	};
	mAnim->SetAnimeTextures(mAnimations[Idle]);
	mCurrentState = Idle;
	newState = mCurrentState;
	mTextComp = new TextComponent(this);
	mTextComp->SetColor({ 255,255,255,255 });

	mCollision = new CollisionComponent(this);
	mCollision->SetSize(PlayerWidth, PlayerHeight);

	SetType(PlayerType);

	mPrevY = 0;
}

//액터 업데이트
void Player::UpdateActor(float deltaTime) {
	Actor::UpdateActor(deltaTime);
	Vector2 pos = GetPosition();

	mPrevY = pos.y;

	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;


	if(pos.y<screen_height - PlayerHeight/2) mDownSpeed += Gravity;

	if (pos.x < PlayerWidth/2) { pos.x = PlayerWidth/2; }
	else if (pos.x > screen_width) { pos.x = screen_width; }
	if (pos.y < PlayerHeight/2) { pos.y = PlayerHeight/2; }
	else if (pos.y > screen_height - PlayerHeight/2) { pos.y = screen_height - PlayerHeight/2;
	mIsJampping = false;
	}

	SetPosition(pos);
	mTextComp->SetText(to_string(GetPosition().x) + ", " + to_string(GetPosition().y));
}

void Player::ProcessKeyBoard(const uint8_t* state) {

	if (state[SDL_SCANCODE_D]) {
		mRightSpeed = 200.0f;
		newState = Move;
		mAnim->SetFlip(SDL_FLIP_NONE);
	}
	else if (state[SDL_SCANCODE_A]) {
		mRightSpeed = -200.0f;
		newState = Move;	
		mAnim->SetFlip(SDL_FLIP_HORIZONTAL);

	}
	else {
		mRightSpeed = 0.0f;
		newState = Idle;
	}

	if (state[SDL_SCANCODE_SPACE] && !mIsJampping) {
		mDownSpeed = -400.f;
		newState = Jamp;	
		mIsJampping = true;
	}
	
	if (newState == Jamp) {
		mCurrentState = newState;
		mAnim->SetAnimeTextures(mAnimations[newState]);
		mAnim->SetAnimFPS(8);
	}
	else if (newState != mCurrentState && !mIsJampping) {
		mCurrentState = newState;
		mAnim->SetAnimeTextures(mAnimations[newState]);
		if (newState == Move) mAnim->SetAnimFPS(12);
		else mAnim->SetAnimFPS(24);
	}
}

void Player::OnCollision(Actor* other) {
	if (other->GetType() == GroundType) {
		float playerBottom = GetPosition().y + PlayerHeight / 2;
		float groundTop = other->GetPosition().y - other->GetScale()*GroundHeight / 2;
		float preplayerBottom = mPrevY + PlayerHeight / 2;

		//위에서 충돌
		if (preplayerBottom <= groundTop && playerBottom >= groundTop)
		{
			Vector2 pos = GetPosition();
			pos.y = other->GetPosition().y - (PlayerHeight / 2 + other->GetScale() * GroundHeight / 2);
			SetPosition(pos);
			mDownSpeed = 0;
			mIsJampping = false;
		}	
	}
}