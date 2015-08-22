#pragma once;

#include <MathDefine.h>
#include <Types.h>
 
namespace math
{
	struct Vector2D
	{
		explicit Vector2D(efloat x = 0.0f, efloat y = 0.0f) :x(x), y(y)
		{
		}

		explicit Vector2D(efloat data[2]) :x(data[0]), y(data[1])
		{
		}

		union
		{
			efloat data[2];

			struct
			{
				efloat x;
				efloat y;
			};

			struct
			{
				efloat u;
				efloat v;
			};

			struct
			{
				efloat r;
				efloat g;
			};

		};
		

		inline efloat dot(const Vector2D& rhs) const
		{
			return this->x * rhs.x + this->y * rhs.y;
		}

		inline efloat length() const
		{
			return sqrt(dot(*this));
		}


		inline Vector2D& operator+=(const Vector2D& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		inline Vector2D& operator+=(efloat scaler)
		{
			this->x += scaler;
			this->y += scaler;
			return *this;
		}

		inline Vector2D& operator-=(const Vector2D& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			return *this;
		}

		inline Vector2D& operator-=(efloat scaler)
		{
			this->x -= scaler;
			this->y -= scaler;
			return *this;
		}

		inline Vector2D& operator*=(const Vector2D& rhs)
		{
			this->x *= rhs.x;
			this->y *= rhs.y;
			return *this;
		}

		inline Vector2D& operator*=(efloat scaler)
		{
			this->x *= scaler;
			this->y *= scaler;
			return *this;
		}

		inline Vector2D& operator/=(const Vector2D& rhs)
		{
			this->x /= rhs.x;
			this->y /= rhs.y;
			return *this;
		}

		inline Vector2D& operator/=(efloat scaler)
		{
			this->x /= scaler;
			this->y /= scaler;
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

		inline efloat operator[](const int& index) const
		{
			return data[index];
		}

		inline efloat distance(const Vector2D& rhs) const
		{
			return sqrt(((rhs.x - this->x)*(rhs.x - this->x))-((rhs.x - this->x)*(rhs.x - this->x)));
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

	inline bool operator==(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.x==rhs.x && lhs.y == rhs.y;
	}

	inline bool operator!=(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.x != rhs.x || lhs.y != rhs.y;
	}

}








