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

#include "Shader.hpp"

#include <fstream>
#include <iostream>
#include <vector>

#include <GL/glew.h>

namespace Miruela
{
	Shader::Shader(const std::string & filePath, const Type & type)
	{
		std::ifstream stream(filePath);
		if (stream.is_open())
		{
			std::string fileContent = "";
			std::string line;
			while (std::getline(stream, line))
			{
				fileContent += line + "\n";
			}

			stream.close();

			GLenum shaderType;
			if (type == VERTEX)
				shaderType = GL_VERTEX_SHADER;
			else if (type == FRAGMENT)
				shaderType = GL_FRAGMENT_SHADER;

			shader = glCreateShader(shaderType);

			const char * cCharFileContent = fileContent.data();
			glShaderSource(shader, 1, &cCharFileContent, nullptr);
			glCompileShader(shader);

			GLint result = GL_FALSE;
			int infoLogLength;

			glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
			if (infoLogLength > 0) {
				std::vector<char> errorMessage(infoLogLength + 1);
				glGetShaderInfoLog(shader, infoLogLength, NULL, &errorMessage[0]);
				printf("%s\n", &errorMessage[0]);
			}
		}
	}


	Shader::~Shader()
	{
		glDeleteShader(shader);
	}
}