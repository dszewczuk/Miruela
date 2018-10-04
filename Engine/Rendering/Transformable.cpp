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

#include "Transformable.hpp"

namespace Miruela
{
	Transformable::Transformable(const Vector3 & position, const Vector3 & scale)
		:position(position), scale(scale)
	{
	}


	Matrix Transformable::getMatrix()
	{
		Matrix matrix;
		matrix = matrix.translate(matrix, position);
		matrix = matrix.scale(matrix, scale);
		return matrix;
	}


	Vector3 Transformable::getPosition() const
	{
		return position;
	}


	void Transformable::setPosition(const Vector3 & position)
	{
		this->position = position;
	}


	void Transformable::move(const Vector3 & relative)
	{
		position += relative;
	}


	Vector3 Transformable::getScale() const
	{
		return scale;
	}


	void Transformable::setScale(const Vector3 & scale)
	{
		this->scale = scale;
	}
}