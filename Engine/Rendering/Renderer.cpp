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

#include "Mesh.hpp"
#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Mesh.hpp"

#include <GL/glew.h>

namespace Miruela
{
	Renderer::Renderer(const std::string & vsPath, const std::string & fsPath)
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
		meshes.clear();
		delete shaderProgram;
	}


	void Renderer::submit(Mesh * mesh)
	{
		meshes.push_back(mesh);
	}


	void Renderer::render()
	{
		shaderProgram->bind();
		while(!meshes.empty())
		{
			auto mesh = meshes.front(); meshes.pop_front();
			mesh->bind();
			glDrawElements(GL_TRIANGLES, mesh->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
		}
	}
}