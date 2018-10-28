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

#include "Game.hpp"

#include "GameState.hpp"

#include "../System/Window.hpp"
#include "../System/EventManager.hpp"

#include "../Rendering/Renderer.hpp"
#include "../Rendering/OrthographicCamera.hpp"

namespace Miruela
{
	Game::Game(const int & width, const int & height)
	{
		window = new Window(Vector2((float)width, (float)height));
		camera = new OrthographicCamera(window);
		renderer = new Renderer(camera, "vs.glsl", "fs.glsl");
		event = new Event;
	}


	Game::~Game()
	{
		delete window;
		delete renderer;
		delete event;
	}


	void Game::run()
	{
		float now = 0, last = 0, delta = 0;

		EventManager eventManager;

		bool quit = false;
		while (!quit)
		{
			now = (float)SDL_GetTicks();
			delta = now - last;
			last = now;

			while (eventManager.pollEvents(event))
			{
				if (event->state == Event::WINDOW_CLOSED)
					quit = true;

				gameState->onEvent(event);
			}

			gameState->update(delta);

			window->clear(0.2f, 0.2f, 0.2f, 0.0f);

			gameState->render();
			renderer->render(window);

			window->render();
		}
	}

	
	
	Renderer * Game::getRenderer() const
	{
		return renderer;
	}


	Window * Game::getWindow() const
	{
		return window;
	}


	Camera * Game::getCamera() const
	{
		return camera;
	}
}