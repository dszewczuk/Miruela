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

#pragma once

#include "../Math/Vector2.hpp"

namespace Miruela
{
	class SDLWindow;
	class Window
	{
	public:
		Window(const Miruela::Vector2 & size);
		~Window();
		
		Miruela::Vector2 getSize() const;

		void clear(const float & r, const float & g, const float & b, const float & a) const;
		void render() const;
	private:
		SDLWindow * window;
		Miruela::Vector2 size;
	};
}