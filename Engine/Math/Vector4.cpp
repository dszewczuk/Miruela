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

#include "Vector4.hpp"

#include <cmath>

namespace Miruela
{
	Vector4::Vector4(void)
		:Vector4(0, 0, 0, 0)
	{
	}


	Vector4::Vector4(const float & value)
		: Vector4(value, value, value, value)
	{
	}


	Vector4::Vector4(const float & x, const float & y, const float & z, const float & w)
		: x(x), y(y), z(z), w(w)
	{
	}


	void Vector4::normalizeSelf()
	{
		if (length() > 0)
		{
			x /= length();
			y /= length();
			z /= length();
			w /= length();
		}
	}


	Vector4 Vector4::normalize() const
	{
		if (length() > 0)
			return Vector4(x / length(), y / length(), z / length(), w / length());
		return Vector4(0, 0, 0, 0);
	}


	float Vector4::length() const
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
	}


	Vector4 Vector4::operator+(const Vector4 & other)
	{
		return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
	}


	Vector4 Vector4::operator-(const Vector4 & other)
	{
		return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
	}


	Vector4 Vector4::operator*(const Vector4 & other)
	{
		return Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
	}


	Vector4 Vector4::operator/(const Vector4 & other)
	{
		return Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
	}


	void Vector4::operator+=(const Vector4 & other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
	}


	void Vector4::operator-=(const Vector4 & other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
	}


	void Vector4::operator*=(const Vector4 & other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
	}


	void Vector4::operator/=(const Vector4 & other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
	}


	bool Vector4::operator==(const Vector4 & other)
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}


	bool Vector4::operator!=(const Vector4 & other)
	{
		return !(operator==(other));
	}
}