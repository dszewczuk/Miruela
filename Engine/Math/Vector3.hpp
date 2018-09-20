#pragma once

namespace Miruela
{
	struct Vector3
	{
		float x, y, z;

		Vector3(void);
		Vector3(const float & value);
		Vector3(const float & x, const float & y, const float & z);

		void normalizeSelf();
		Vector3 normalize();

		float length();

		Vector3 operator+(const Vector3 & other);
		Vector3 operator-(const Vector3 & other);
		Vector3 operator*(const Vector3 & other);
		Vector3 operator/(const Vector3 & other);

		void operator+=(const Vector3 & other);
		void operator-=(const Vector3 & other);
		void operator*=(const Vector3 & other);
		void operator/=(const Vector3 & other);

		bool operator==(const Vector3 & other);
		bool operator!=(const Vector3 & other);
	};
}