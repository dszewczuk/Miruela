#include "Vector3.hpp"

#include <cmath>

namespace Miruela
{
	Vector3::Vector3(void)
		:Vector3(0, 0, 0)
	{
	}


	Vector3::Vector3(const float & value)
		:Vector3(value, value, value)
	{
	}


	Vector3::Vector3(const float & x, const float & y, const float & z)
		:x(x), y(y), z(z)
	{
	}


	void Vector3::normalizeSelf()
	{
		if (length() > 0)
		{
			x /= length();
			y /= length();
			z /= length();
		}
	}


	Vector3 Vector3::normalize()
	{
		if (length() > 0)
			return Vector3(x / length(), y / length(), z / length());
		return Vector3(0, 0, 0);
	}


	float Vector3::length()
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}


	Vector3 Vector3::operator+(const Vector3 & other)
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}


	Vector3 Vector3::operator-(const Vector3 & other)
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}


	Vector3 Vector3::operator*(const Vector3 & other)
	{
		return Vector3(x * other.x, y * other.y, z * other.z);
	}


	Vector3 Vector3::operator/(const Vector3 & other)
	{
		return Vector3(x / other.x, y / other.y, z / other.z);
	}


	void Vector3::operator+=(const Vector3 & other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}


	void Vector3::operator-=(const Vector3 & other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}


	void Vector3::operator*=(const Vector3 & other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
	}


	void Vector3::operator/=(const Vector3 & other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
	}


	bool Vector3::operator==(const Vector3 & other)
	{
		return x == other.x && y == other.y && z == other.z;
	}


	bool Vector3::operator!=(const Vector3 & other)
	{
		return !(operator==(other));
	}
}