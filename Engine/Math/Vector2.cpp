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