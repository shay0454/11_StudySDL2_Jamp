#ifndef PLAYER_H
#define PLAYER_H
#include "Actor.h"
#include <unordered_map>
#define PlayerWidth 64
#define PlayerHeight 128
#define Gravity 9.8
class Player : public Actor {
	public:
		enum PlayerState{ Idle, Move, Attack, Jamp };
		Player(class Game* game);
		void UpdateActor(float deltaTime) override;
		void ProcessKeyBoard(const uint8_t* state);
		float GetRightSpeed() const { return mRightSpeed; }
		float GetDownSpeed() const { return mDownSpeed; }
		void OnCollision(Actor* other) override;
	private:
		float mRightSpeed;
		float mDownSpeed;
		class TextComponent* mTextComp;

		bool mIsJampping;
		PlayerState mCurrentState,newState;
		class AnimSpriteComponent* mAnim;
		unordered_map<int, vector<SDL_Texture*>> mAnimations;
		float mPrevY;
		class CollisionComponent* mCollision;
};
#endif // !PLAYER_H
