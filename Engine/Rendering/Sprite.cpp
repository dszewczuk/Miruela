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

#include "Sprite.hpp"

#include "Texture.hpp"
#include "Mesh.hpp"
#include "ShaderProgram.hpp"
#include "Transformable.hpp"

#include "../Math/Vector2.hpp"
#include "../Math/Vector3.hpp"
#include "../Math/Matrix.hpp"

#include <vector>

namespace Miruela
{
	Sprite::Sprite(Texture * texture, const Vector2 & position, const Vector2 & size)
		:Renderable(6), texture(texture), Transformable(Vector3(position.x, position.y, 0), Vector3(size.x, size.y, 0))
	{
		std::vector<Miruela::Vector3> vertices =
		{
			{ -0.5f, 0.5f, 0.0f },
			{ 0.5f, 0.5f, 0.0f },
			{ -0.5f, -0.5f, 0.0f },
			{ 0.5f, -0.5f, 0.0f }
		};

		std::vector<Miruela::Vector2> uvs =
		{
			{ 0.0f, 1.0f },
			{ 1.0f, 1.0f },
			{ 0.0f, 0.0f },
			{ 1.0f, 0.0f }
		};

		std::vector<unsigned int> indices =
		{
			0, 1, 2,
			2, 3, 1
		};

		mesh = new Mesh(vertices, uvs, indices);
	}


	Sprite::~Sprite()
	{
		delete mesh;
	}


	void Sprite::render(ShaderProgram * shaderProgram)
	{
		texture->bind();
		
		shaderProgram->setMatrixUniform("transformation", getMatrix()); //temporary here, just put here to test matrices

		mesh->bind();
	}
}