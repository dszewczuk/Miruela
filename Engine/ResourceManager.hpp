#pragma once

#include <string>
#include <unordered_map>

namespace Miruela
{
	class Resource;
	class ResourceManager
	{
	public:
		template<class T, class ... Type>
		void load(const std::string & name, Type && ... args)
		{
			resources[name] = new T(args...);
		}

		template<class T>
		T * get(const std::string & name)
		{
			return dynamic_cast<T*>(resources[name]);
		}
	private:
		std::unordered_map<std::string, Resource*> resources;
	};
}