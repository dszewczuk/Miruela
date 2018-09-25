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

#include "Window.hpp"

#include <GL/glew.h>
#include <cassert>
#include <iostream>

namespace Miruela
{
	Window::Window(const int & width, const int & height)
	{
		window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
		context = SDL_GL_CreateContext(window);

		glewExperimental = GL_TRUE;
		glewInit();
	}


	Window::~Window()
	{
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
	}


	void Window::clear(const float & r, const float & g, const float & b, const float & a) const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
	}


	void Window::render() const
	{
		SDL_GL_SwapWindow(window);
	}
}