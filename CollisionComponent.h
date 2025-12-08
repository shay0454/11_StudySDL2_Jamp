#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H
#include "Component.h"

class CollisionComponent : Component {
	public:
		CollisionComponent(class Actor* owner);

		void SetSize(float w, float h) { mWidth = w, mHeight = h; }
		bool Intersect(const CollisionComponent* other) const;
		
	private:
		float mWidth;
		float mHeight;
};
#endif // !COLLISIONCOMPONENT_H
