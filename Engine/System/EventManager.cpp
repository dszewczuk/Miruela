#include "EventManager.hpp"

namespace Miruela
{
	int EventManager::pollEvents()
	{
		return SDL_PollEvent(&event);
	}
	bool EventManager::isWindowClosed()
	{
		return event.type == SDL_QUIT;
	}
}