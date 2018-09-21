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

#include "Buffer.hpp"

#include <GL/glew.h>

namespace Miruela
{
	Buffer::Buffer(const Type & type, const Usage & usage, const unsigned int & size, const void * data)
		:bufferType(type)
	{
		GLenum uusage;

		if (type == ELEMENT)
			bufferType = GL_ELEMENT_ARRAY_BUFFER;
		else if (type == BUFFER)
			bufferType = GL_ARRAY_BUFFER;

		if (usage == STATIC)
			uusage = GL_STATIC_DRAW;
		else if (usage == DYNAMIC)
			uusage = GL_DYNAMIC_DRAW;

		glGenBuffers(1, &index);
		bind();
		glBufferData(bufferType, size, data, uusage);
	}


	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &index);
	}


	void Buffer::enableVertexAttrib(const int & index, const int & size, const int & valueType) const
	{
		bind();
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, valueType, GL_FALSE, 0, nullptr);
	}


	void Buffer::bind() const
	{
		glBindBuffer(bufferType, index);
	}
}