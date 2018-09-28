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
	Sprite::Sprite(Texture * texture)
		:Renderable(6), texture(texture)
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
			{ 0.f, 1.0f },
			{ 1.f, 1.f },
			{ 0.f, 0.f },
			{ 1.f, 0.f }
		};

		std::vector<unsigned int> indices =
		{
			0, 1, 2,
			2, 3, 1
		};

		mesh = new Mesh(vertices, uvs, indices);

		transformable = new Transformable(Vector3(0.0f, 0.5f, 0.0f), Vector3(0.5f));
	}


	Sprite::~Sprite()
	{
		delete mesh;
	}


	void Sprite::render(ShaderProgram * shaderProgram)
	{
		transformable->move(Vector3(0.00005f, 0.0f, 0.0f));

		texture->bind();
		
		shaderProgram->setMatrixUniform("trans", transformable->getMatrix()); //temporary here, just put here to test matrices

		mesh->bind();
	}
}