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

#include "EventManager.hpp"

#include <SDL_events.h>

namespace Miruela
{
	bool EventManager::pollEvents(Event * event)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				event->state = Event::WINDOW_CLOSED;
			
			if (e.type == SDL_MOUSEBUTTONDOWN)
				event->state = Event::MOUSEBUTTON_DOWN;

			if (e.type == SDL_MOUSEBUTTONUP)
				event->state = Event::MOUSEBUTTON_UP;

			if (e.type == SDL_KEYDOWN)
			{
				event->state = Event::KEY_DOWN;
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					event->keys['w'] = true;
					break;
				case SDLK_s:
					event->keys['s'] = true;
					break;
				case SDLK_a:
					event->keys['a'] = true;
					break;
				case SDLK_d:
					event->keys['d'] = true;
					break;
				}
			}

			if (e.type == SDL_KEYUP)
			{
				event->state = Event::KEY_UP;
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					event->keys['w'] = false;
					break;
				case SDLK_s:
					event->keys['s'] = false;
					break;
				case SDLK_a:
					event->keys['a'] = false;
					break;
				case SDLK_d:
					event->keys['d'] = false;
					break;
				}
			}

			return 1;
		}
		else
		{
			return 0;
		}
	}
}