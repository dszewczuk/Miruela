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

#include <unordered_map>
#include <typeinfo>
#include <string>

#include "Component.hpp"

namespace Miruela
{
	class Entity
	{
	public:
		template<class T1, class T2, class ... Types> //Simplification of t1 and t2
		void appendComponent(Types && ... args)
		{
			components[typeid(T1).name()] = new T2(this, args...);
		}

		template<class T>
		T* getComponent()
		{
			return dynamic_cast<T*>(components[typeid(T).name()]);
		}

	private:
		std::unordered_map<std::string, Component*> components;
	};
}