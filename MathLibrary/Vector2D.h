#pragma once;

#include <MathDefine.h>

 
namespace math
{
	struct Vector2D
	{
		explicit Vector2D(efloat x = 0.0f, efloat y = 0.0f) :x(x), y(y)
		{
		}

		efloat x, y;


		inline efloat dot(Vector2D* rhs)
		{
			return this->x * rhs->x + this->y * rhs->y;
		}

		inline Vector2D& operator+=(const Vector2D& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		inline Vector2D& operator-=(const Vector2D& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			return *this;
		}

		Vector2D(const Vector2D& source)
		{
			this->x = source.x;
			this->y = source.y;
		}

		inline Vector2D& operator=(const Vector2D& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			return *this;
		}

		inline Vector2D& swap()
		{
			const efloat temp = this->x;
			this->x = this->y;
			this->y = temp;
			return *this;
		}

		inline efloat& operator[](const int& index)
		{
			return *(&this->x + index);
		}
	};

	inline Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs)
	{
		return Vector2D(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	inline Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs)
	{
		return Vector2D(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	inline Vector2D operator*(efloat scaler, const Vector2D& rhs)
	{
		return Vector2D(scaler*rhs.x, scaler*rhs.y);
	}

	inline Vector2D operator*(const Vector2D& lhs, efloat scaler)
	{
		return scaler * lhs;
	}

	inline Vector2D operator/(const Vector2D& lhs, efloat scaler)
	{
		return Vector2D(lhs.x / scaler, lhs.y / scaler);
	}

}








