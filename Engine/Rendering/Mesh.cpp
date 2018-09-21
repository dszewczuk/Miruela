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

#include "Mesh.hpp"

#include "../Math/Vector2.hpp"
#include "../Math/Vector3.hpp"

#include <GL/glew.h>

namespace Miruela
{
	Mesh::Mesh(const std::vector<Vector3> & vertices, const std::vector<Vector2> & uvs, const std::vector<unsigned int> & indices)
		:element(Miruela::Buffer::Type::ELEMENT, Miruela::Buffer::Usage::STATIC, sizeof(unsigned int) * indices.size(), &indices[0]),
		vertex(Miruela::Buffer::Type::BUFFER, Miruela::Buffer::Usage::STATIC, sizeof(Miruela::Vector3) * vertices.size(), &vertices[0]),
		textureCoord(Miruela::Buffer::Type::BUFFER, Miruela::Buffer::Usage::STATIC, sizeof(Miruela::Vector2) * uvs.size(), &uvs[0]), indicesCount(indices.size()),
		vertexArray()
	{
		vertexArray.bind();

		vertex.enableVertexAttrib(0, 3, GL_FLOAT);
		textureCoord.enableVertexAttrib(1, 2, GL_FLOAT);
	}


	void Mesh::bind() const
	{
		vertexArray.bind();
		element.bind();

		glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);//Temporary here
	}
}