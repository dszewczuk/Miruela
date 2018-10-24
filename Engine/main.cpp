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

#include "Core/Game.hpp"
#include "Core/GameState.hpp"
#include "Core/Entity.hpp"

#include "Rendering/Texture.hpp"
#include "Rendering/Sprite.hpp"
#include "Rendering/Renderer.hpp"

#include "Math/Vector3.hpp"

#include "System/Event.hpp"

#include <iostream>

#undef main

class MainGameState : public Miruela::GameState
{
public:
	MainGameState(Miruela::Game * game)
		:GameState(game)
	{
		getResourceManager()->load<Miruela::Texture>("texture", "texture.png");

		player = root->appendChild("player");

		player->appendComponent<Miruela::Transformable>(Miruela::Vector3(0, 0, 0), Miruela::Vector3(64, 64, 0));
		player->appendComponent<Miruela::Renderable, Miruela::Sprite>(getResourceManager()->get<Miruela::Texture>("texture"));
	}

	void render() override
	{
		getGame()->getRenderer()->submit(player);
	}

	void update(const float & deltaTime) override
	{
		
	}

	void onEvent(Miruela::Event * event) override
	{
		if (event->state == Miruela::Event::KEY_DOWN)
			player->getComponent<Miruela::Transformable>()->move({ 1.f, 0.f, 0.f });
	}

private:
	Miruela::Entity * player;
};

int main()
{
	Miruela::Game game(800, 600);
	MainGameState state(&game);
	game.run();

	return 0;
}