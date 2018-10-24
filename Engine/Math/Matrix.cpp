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

#include "Matrix.hpp"

#include "Vector3.hpp"

#include <sstream>

namespace Miruela
{
	Matrix::Matrix()
	{
		memset(&value, 0, sizeof(float) * 16);
	}


	Matrix::Matrix(const float & v)
	{
		Matrix();
		value[0][0] = v;
		value[1][1] = v;
		value[2][2] = v;
		value[3][3] = v;
	}


	Matrix Matrix::identity()
	{
		return Matrix(1.0f);
	}


	Matrix Matrix::scale(const Matrix & matrix, const Vector3 & scaling)
	{
		Matrix m = matrix;
		m.value[0][0] = scaling.x;
		m.value[1][1] = scaling.y;
		m.value[2][2] = scaling.z;
		m.value[3][3] = 1.0f;
		return m;
	}


	Matrix Matrix::translate(const Matrix & matrix, const Vector3 & translation)
	{
		Matrix m = matrix;
		m.value[3][0] = translation.x;
		m.value[3][1] = translation.y;
		m.value[3][2] = translation.z;
		m.value[3][3] = 1.0f;
		return m;
	}


	Matrix Matrix::orthographic(const float & left, const float & right, const float & top, const float & bottom, const float & near, const float & far)
	{
		Matrix m;
		m.value[0][0] = 2 / (right - left);
		m.value[1][1] = 2 / (top - bottom);
		m.value[2][2] = -2 / (far - near);

		m.value[3][0] = -(right + left) / (right - left);
		m.value[3][1] = -(top + bottom) / (top - bottom);
		m.value[3][2] = -(far + near) / (far - near);
		m.value[3][3] = 1;

		return m;
	}
}