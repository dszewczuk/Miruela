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

#include <array>

namespace Miruela
{
	struct Vector3;
	struct Matrix
	{
		std::array<std::array<float, 4>, 4> value;

		Matrix();
		Matrix(const float & value);

		static Matrix identity();
		static Matrix scale(const Matrix & matrix, const Vector3 & scaling);
		static Matrix translate(const Matrix & matrix, const Vector3 & translation);

		static Matrix orthographic(const float & left, const float & right, const float & top, const float & bottom, const float & near, const float & far);
	};
}