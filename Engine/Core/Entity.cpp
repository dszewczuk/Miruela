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

#include "Entity.hpp"

namespace Miruela
{
	Entity::Entity()
		:parent(nullptr)
	{
	}


	Entity::~Entity()
	{
		for (auto & child : children)
		{
			delete child.second;
		}

		for (auto & component : components)
		{
			delete component.second;
		}
	}


	Entity * Entity::appendChild(const std::string & name)
	{
		children[name] = new Entity;
		children[name]->parent = this;

		return getChild(name);
	}


	Entity * Entity::getChild(const std::string & name)
	{
		return children[name];
	}
}