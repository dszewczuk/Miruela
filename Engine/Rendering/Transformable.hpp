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

#include "../Math/Vector3.hpp"

#include "../Math/Matrix.hpp"

namespace Miruela
{
	class Transformable
	{
	public:
		Transformable(const Vector3 & position=Vector3(0.0f), const Vector3 & scale=Vector3(0.5f));

		Matrix getMatrix();

		Vector3 getPosition() const;
		void setPosition(const Vector3 & position);

		Vector3 getScale() const;
		void setScale(const Vector3 & scale);

		void move(const Vector3 & relative);
	private:
		Vector3 position;
		Vector3 scale;
	};
}