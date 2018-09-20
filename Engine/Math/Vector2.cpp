#include "Vector2.hpp"

#include <cmath>

namespace Miruela
{
	Vector2::Vector2(void)
		:Vector2(0, 0)
	{
	}


	Vector2::Vector2(const float & value)
		:Vector2(value, value)
	{
	}


	Vector2::Vector2(const float & x, const float & y)
		:x(x), y(y)
	{
	}


	void Vector2::normalizeSelf()
	{
		if (length() > 0)
		{
			x /= length();
			y /= length();
		}
	}


	Vector2 Vector2::normalize()
	{
		if (length() > 0)
			return Vector2(x / length(), y / length());
		return Vector2(0, 0);
	}


	float Vector2::length()
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}


	Vector2 Vector2::operator+(const Vector2 & other)
	{
		return Vector2(x + other.x, y + other.y);
	}


	Vector2 Vector2::operator-(const Vector2 & other)
	{
		return Vector2(x - other.x, y - other.y);
	}


	Vector2 Vector2::operator*(const Vector2 & other)
	{
		return Vector2(x * other.x, y * other.y);
	}


	Vector2 Vector2::operator/(const Vector2 & other)
	{
		return Vector2(x / other.x, y / other.y);
	}


	void Vector2::operator+=(const Vector2 & other)
	{
		x += other.x;
		y += other.y;
	}


	void Vector2::operator-=(const Vector2 & other)
	{
		x -= other.x;
		y -= other.y;
	}


	void Vector2::operator*=(const Vector2 & other)
	{
		x *= other.x;
		y *= other.y;
	}


	void Vector2::operator/=(const Vector2 & other)
	{
		x /= other.x;
		y /= other.y;
	}

	bool Vector2::operator==(const Vector2 & other)
	{
		return x == other.x && y == other.y;
	}


	bool Vector2::operator!=(const Vector2 & other)
	{
		return !(operator==(other));
	}
}