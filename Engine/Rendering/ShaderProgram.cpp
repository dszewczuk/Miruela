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

#include "ShaderProgram.hpp"

#include "Shader.hpp"

#include "../Math/Matrix.hpp"

#include <GL/glew.h>

namespace Miruela
{
	ShaderProgram::ShaderProgram(const std::vector<Shader*> & shaders)
	{
		shaderProgram = glCreateProgram();

		for (auto & shader : shaders)
		{
			glAttachShader(shaderProgram, shader->shader);
		}

		glLinkProgram(shaderProgram);

		GLint result = GL_FALSE;
		int infoLogLength;

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 0) {
			std::vector<char> errorMessage(infoLogLength + 1);
			glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, &errorMessage[0]);
			printf("%s\n", &errorMessage[0]);
		}

		for (auto & shader : shaders)
		{
			glDetachShader(shaderProgram, shader->shader);
		}
	}


	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(shaderProgram);
	}


	void ShaderProgram::setMatrixUniform(const std::string & name, const Matrix & matrix)
	{
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix.value[0][0]);
	}

	
	void ShaderProgram::bind() const
	{
		glUseProgram(shaderProgram);
	}


	unsigned int ShaderProgram::getUniformLocation(const std::string & name)
	{
		unsigned int location = glGetUniformLocation(shaderProgram, name.data());
		if (location < 0)
		{
			return 0;
		}
		return location;
	}
}