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

#include "Rendering/Mesh.hpp"
#include "Rendering/ShaderProgram.hpp"
#include "Rendering/Shader.hpp"
#include "Rendering/Texture.hpp"
#include "Rendering/Buffer.hpp"
#include "Rendering/VertexArray.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Sprite.hpp"

#include "Math/Vector3.hpp"
#include "Math/Vector2.hpp"

#undef main

int main()
{
	Miruela::Window window(800, 600);
	Miruela::EventManager eventManager;

	Miruela::Renderer renderer("vs.glsl", "fs.glsl");

	Miruela::Texture texture("texture.png");
	
	Miruela::Sprite sprite(&texture);

	while (!eventManager.isWindowClosed())
	{
		while (eventManager.pollEvents())
		{

		}
		window.clear(0.2, 0.2, 0.2, 0.0);

		renderer.submit(&sprite);
		renderer.render();

		window.render();
	}

	return 0;
}