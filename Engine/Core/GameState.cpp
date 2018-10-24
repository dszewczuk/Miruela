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

#include "GameState.hpp"

#include "Game.hpp"

namespace Miruela
{
	GameState::GameState(Game * game)
		:game(game)
	{
		game->gameState = this;
		root = new Entity;
		resourceManager = new ResourceManager();
	}

	GameState::~GameState()
	{
		delete root;
		delete resourceManager;
	}


	Game * GameState::getGame() const
	{
		return game;
	}

	ResourceManager * GameState::getResourceManager() const
	{
		return resourceManager;
	}
}