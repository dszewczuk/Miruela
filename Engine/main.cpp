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

#include "System/Window.hpp"
#include "System/EventManager.hpp"

#include "Rendering/MeshRenderer.hpp"
#include "Rendering/ShaderProgram.hpp"
#include "Rendering/Shader.hpp"
#include "Rendering/Texture.hpp"

#include "Math/Vector3.hpp"
#include "Math/Vector2.hpp"

#include <iostream>

#undef main

int main()
{
	Miruela::Window window(800, 600);
	Miruela::EventManager eventManager;

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
		{ 1.f, 1.f},
		{ 0.f, 0.f },
		{ 1.f, 0.f }
	};

	std::vector<unsigned int> indices =
	{
		0, 1, 2,
		2, 3, 1
	};

	Miruela::MeshRenderer meshRenderer(vertices, uvs, indices);

	std::vector<Miruela::Shader*> shaders = 
	{
		new Miruela::Shader("vs.glsl", Miruela::Shader::VERTEX),
		new Miruela::Shader("fs.glsl", Miruela::Shader::FRAGMENT)
	};

	Miruela::ShaderProgram program(shaders);

	Miruela::Texture texture("texture.png");

	shaders.clear();

	while (!eventManager.isWindowClosed())
	{
		while (eventManager.pollEvents())
		{

		}
		window.clear(0.2, 0.2, 0.2, 0.0);

		program.bind();

		texture.bind();
		meshRenderer.render();

		window.render();
	}

	return 0;
}