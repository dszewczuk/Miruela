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
	struct Vector4
	{
		float x, y, z, w;

		Vector4(void);
		Vector4(const float & value);
		Vector4(const float & x, const float & y, const float & z, const float & w);

		void normalizeSelf();
		Vector4 normalize() const;

		float length() const;

		Vector4 operator+(const Vector4 & other);
		Vector4 operator-(const Vector4 & other);
		Vector4 operator*(const Vector4 & other);
		Vector4 operator/(const Vector4 & other);

		void operator+=(const Vector4 & other);
		void operator-=(const Vector4 & other);
		void operator*=(const Vector4 & other);
		void operator/=(const Vector4 & other);

		bool operator==(const Vector4 & other);
		bool operator!=(const Vector4 & other);
	};
}