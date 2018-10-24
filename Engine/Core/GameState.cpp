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