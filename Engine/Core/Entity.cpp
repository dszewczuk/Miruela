#include "Entity.hpp"

namespace Miruela
{
	Entity::Entity()
		:parent(nullptr)
	{
	}

	Entity * Entity::appendChild(const std::string & name)
	{
		entities[name] = new Entity;
		entities[name]->parent = this;

		return getChild(name);
	}

	Entity * Entity::getChild(const std::string & name)
	{
		return entities[name];
	}
}