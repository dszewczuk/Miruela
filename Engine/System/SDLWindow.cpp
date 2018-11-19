#include "SDLWindow.hpp"

namespace Miruela
{
	SDLWindow::SDLWindow(const Miruela::Vector2 & size)
	{
		window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_OPENGL);
		context = SDL_GL_CreateContext(window);
	}

	SDLWindow::~SDLWindow()
	{
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
	}

	void SDLWindow::swap() const
	{
		SDL_GL_SwapWindow(window);
	}
}