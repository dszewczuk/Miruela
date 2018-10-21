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

namespace Miruela
{
	Game::Game(const int & width, const int & height)
	{
		window = new Window(Vector2(width, height));
		renderer = new Renderer("vs.glsl", "fs.glsl");
	}


	Game::~Game()
	{
		delete window;
		delete renderer;
	}


	void Game::run()
	{
		EventManager eventManager;

		while (!eventManager.isWindowClosed())
		{
			while (eventManager.pollEvents())
			{
				gameState->handleEvent(&eventManager);
			}
			gameState->update(1.0f);

			window->clear(0.2, 0.2, 0.2, 0.0);

			gameState->render();
			renderer->render(window);

			window->render();
		}
	}


	void Game::setGameState(GameState * gameState)
	{
		gameState->game = this;
		this->gameState = gameState;
	}
	
	
	Renderer * Game::getRenderer() const
	{
		return renderer;
	}


	Window * Game::getWindow() const
	{
		return window;
	}
}