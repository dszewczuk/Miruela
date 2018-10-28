#include "OrthographicCamera.hpp"

#include "../System/Window.hpp"

namespace Miruela
{
	OrthographicCamera::OrthographicCamera(Window * window, Vector2 position)
	{
		matrix = Matrix::orthographic(position.x, window->getSize().x, position.y, window->getSize().y, -1.0f, 1.0f);
	}
}