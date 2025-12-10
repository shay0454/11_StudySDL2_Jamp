#ifndef GROUND_H
#define GROUND_H
#include "Actor.h"
#define GroundWidth 160
#define GroundHeight 64
class Ground : public Actor{
	public:
		Ground(class Game* game);
		void UpdateActor(float deltaTime) override;
		void OnCollision(Actor* other) override;
	private:
		class TextComponent* mTextComp;

		class AnimSpriteComponent* mAnim;
		class CollisionComponent* mCollision;
};
#endif // !GROUND_H
