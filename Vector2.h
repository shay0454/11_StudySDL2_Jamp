#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
	public:
		float x;
		float y;
		Vector2(float inx=0, float iny=0) {
			x = inx, y = iny;
		}
		Vector2 operator*(float f) {
			return Vector2(x * f, y * f);
		}
		Vector2 operator+(const Vector2& v) {
			return Vector2(this->x + v.x, this->y + v.y);
		}
		Vector2& operator+=(const Vector2& v) {
			x += v.x;
			y += v.y;
			return *this;
		}
};

#endif // !VECTOR2_H
