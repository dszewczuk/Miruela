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

#include <map>

namespace Miruela
{
	struct Event
	{
		enum State
		{
			MOUSE_MOVED = 0,
			MOUSEBUTTON_UP,
			MOUSEBUTTON_DOWN,

			KEY_UP,
			KEY_DOWN,

			WINDOW_CLOSED
		};

		State state;
		std::map<char, bool> keys;
	};
}