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

#include "Rendering/Texture.hpp"
#include "Rendering/Sprite.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/ShaderProgram.hpp"

#include "Math/Vector3.hpp"
#include "Math/Matrix.hpp"

#include "System/EventManager.hpp"

#undef main

class MainGameState : public Miruela::GameState
{
public:
	MainGameState()
	{
		getResourceManager()->load<Miruela::Texture>("texture", "texture.png");
		sprite = new Miruela::Sprite(getResourceManager()->get<Miruela::Texture>("texture"), Miruela::Vector2(0, 0), Miruela::Vector2(64, 64));
	}

	~MainGameState()
	{
		delete sprite;
	}

	void draw() override
	{
		getGame()->getRenderer()->submit(sprite);
	}

	void update(const float & deltaTime) override
	{
		sprite->move(Miruela::Vector3(deltaTime / 10, deltaTime / 20, 0));
	}

	void handleEvent(Miruela::EventManager * eventManager) override
	{
	}

private:
	Miruela::Sprite * sprite;
};

int main()
{
	Miruela::Game game(800, 600);
	MainGameState state;
	game.setGameState(&state);
	game.run();

	return 0;
}