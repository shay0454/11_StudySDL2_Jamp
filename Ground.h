#ifndef GROUND_H
#define GROUND_H
#include "Actor.h"
#define GroundWidth 160
#define GroundHeight 64
class Ground : public Actor{
	public:
		enum GroundType{
			TheGround, Platform, FloatingBlock
		};
		Ground(class Game* game);
		void UpdateActor(float deltaTime) override;
		void OnCollision(Actor* other) override;
		void SetGroundType(GroundType isGround = Platform);
		GroundType GetGroundType() const { return mGroundType; }
	private:
		class TextComponent* mTextComp;

		class AnimSpriteComponent* mAnim;
		class CollisionComponent* mCollision;

		GroundType mGroundType;
};
#endif // !GROUND_H
