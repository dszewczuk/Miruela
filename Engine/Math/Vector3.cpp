/*
	Copyright (C) 2018 Dmitro Szewczuk
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
	Also add information on how to contact you by electronic and paper mail.
*/

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