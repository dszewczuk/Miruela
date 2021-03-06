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

#include "Renderer.hpp"

#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Mesh.hpp"
#include "Renderable.hpp"

#include "../System/Window.hpp"

#include "../Math/Transformable.hpp"

#include <GL/glew.h>

namespace Miruela
{
	Renderer::Renderer(Camera * camera, const std::string & vsPath, const std::string & fsPath)
		:camera(camera)
	{
		std::vector<Miruela::Shader*> shaders =
		{
			new Miruela::Shader(vsPath, Miruela::Shader::VERTEX),
			new Miruela::Shader(fsPath, Miruela::Shader::FRAGMENT)
		};

		shaderProgram = new ShaderProgram(shaders);
		shaders.clear();
	}


	Renderer::~Renderer()
	{
		renderables.clear();
		delete shaderProgram;
	}


	ShaderProgram * Renderer::getShaderProgram()
	{
		return shaderProgram;
	}


	void Renderer::submit(Entity * entity)
	{
		renderables.push_back(std::make_pair<Transformable*, Renderable*>(entity->getComponent<Transformable>(), entity->getComponent<Renderable>()));
	}


	void Renderer::render(const Window * window)
	{
		shaderProgram->bind();
		shaderProgram->setMatrixUniform("projection", camera->getMatrix());
		while(!renderables.empty())
		{
			auto pair = renderables.front(); renderables.pop_front();
			shaderProgram->setMatrixUniform("transformation", pair.first->getMatrix());
			pair.second->render();
			glDrawElements(GL_TRIANGLES, pair.second->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
		}
	}
}