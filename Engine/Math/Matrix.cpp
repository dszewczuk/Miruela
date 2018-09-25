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

#include <sstream>

#include "Vector3.hpp"

namespace Miruela
{
	Matrix::Matrix()
	{
		identity();
	}


	void Matrix::identity()
	{
		memset(&value, 0, sizeof(float) * 16);
		value[0][0] = 1.0f;
		value[1][1] = 1.0f;
		value[2][2] = 1.0f;
		value[3][3] = 1.0f;
	}


	void Matrix::scale(const Vector3 & translation)
	{
		for (auto & column : value)
		{
			column[0] *= translation.x;
			column[1] *= translation.y;
			column[2] *= translation.z;
		}
	}


	void Matrix::translate(const Vector3 & translation)
	{
		value[3][0] = translation.x;
		value[3][1] = translation.y;
		value[3][2] = translation.z;
	}
}