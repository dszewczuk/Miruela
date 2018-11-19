#pragma once

#include <SDL.h>

#include "../Math/Vector2.hpp"

namespace Miruela
{
	class SDLWindow
	{
	public:
		SDLWindow(const Miruela::Vector2 & size);
		~SDLWindow();

		void swap() const;
	private:
		SDL_Window * window;
		SDL_GLContext context;
	};
}