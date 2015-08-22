#pragma once;

#include <MathDefine.h>
#include <Types.h>
 
namespace math
{
	struct Vector2D
	{
		explicit Vector2D(f32 x = 0.0f, f32 y = 0.0f) :x(x), y(y)
		{
		}

		explicit Vector2D(f32 data[2]) :x(data[0]), y(data[1])
		{
		}

		union
		{
			f32 data[2];

			struct
			{
				f32 x;
				f32 y;
			};

			struct
			{
				f32 u;
				f32 v;
			};

			struct
			{
				f32 r;
				f32 g;
			};

		};
		

		inline f32 dot(const Vector2D& rhs) const
		{
			return this->x * rhs.x + this->y * rhs.y;
		}

		inline f32 length() const
		{
			return sqrt(dot(*this));
		}


		inline Vector2D& operator+=(const Vector2D& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		inline Vector2D& operator+=(f32 scaler)
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

		inline Vector2D& operator-=(f32 scaler)
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

		inline Vector2D& operator*=(f32 scaler)
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

		inline Vector2D& operator/=(f32 scaler)
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
			const f32 temp = this->x;
			this->x = this->y;
			this->y = temp;
			return *this;
		}

		inline f32 operator[](const int& index) const
		{
			return data[index];
		}

		inline f32 distance(const Vector2D& rhs) const
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


	inline Vector2D operator*(f32 scaler, const Vector2D& rhs)
	{
		return Vector2D(scaler*rhs.x, scaler*rhs.y);
	}

	inline Vector2D operator*(const Vector2D& lhs, f32 scaler)
	{
		return scaler * lhs;
	}


	inline Vector2D operator/(const Vector2D& lhs, f32 scaler)
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








