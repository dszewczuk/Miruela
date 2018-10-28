#pragma once

#include "Camera.hpp"

#include "../Math/Vector2.hpp"

namespace Miruela
{
	class Window;
	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera(Window * window, Vector2 position = Vector2(0));
	};
}