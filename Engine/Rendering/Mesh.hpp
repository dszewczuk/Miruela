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

#include <vector>

#include "Buffer.hpp"
#include "VertexArray.hpp"

namespace Miruela
{
	struct Vector3;
	struct Vector2;

	class Mesh
	{
	public:
		Mesh(const std::vector<Vector3> & vertices, const std::vector<Vector2> & uvs, const std::vector<unsigned int> & indices);

		unsigned int getIndicesCount();

		void bind() const;
	private:
		unsigned int indicesCount;

		VertexArray vertexArray;
		Buffer vertex;
		Buffer textureCoord;
		Buffer element;
	};
}