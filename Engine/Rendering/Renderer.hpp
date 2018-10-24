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

#include <string>
#include <deque>

#include "../Core/Entity.hpp"

namespace Miruela
{
	class Transformable;
	class Renderable;
	class ShaderProgram;
	class Mesh;
	class Window;

	class Renderer
	{
	public:
		Renderer(const std::string & vsPath, const std::string & fsPath);
		~Renderer();

		ShaderProgram * getShaderProgram();

		//!Renderable & Transformable components required
		void submit(Entity * entity);
	private:
		void render(const Window * window);
	private:
		ShaderProgram * shaderProgram;
		std::deque<std::pair<Transformable*, Renderable*>> renderables;

		friend class Game;
	};
}