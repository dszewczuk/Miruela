#pragma once

#include <SDL_events.h>

namespace Miruela
{
	class EventManager
	{
	public:
		int pollEvents();
		bool isWindowClosed();
	private:
		SDL_Event event;
	};
};