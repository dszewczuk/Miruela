#pragma once

namespace Miruela
{
	struct Vector2
	{
		float x, y;

		Vector2(void);
		Vector2(const float & value);
		Vector2(const float & x, const float & y);

		void normalizeSelf();
		Vector2 normalize();

		float length();

		Vector2 operator+(const Vector2 & other);
		Vector2 operator-(const Vector2 & other);
		Vector2 operator*(const Vector2 & other);
		Vector2 operator/(const Vector2 & other);

		void operator+=(const Vector2 & other);
		void operator-=(const Vector2 & other);
		void operator*=(const Vector2 & other);
		void operator/=(const Vector2 & other);

		bool operator==(const Vector2 & other);
		bool operator!=(const Vector2 & other);
	};
}