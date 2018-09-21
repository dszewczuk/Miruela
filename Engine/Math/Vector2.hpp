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