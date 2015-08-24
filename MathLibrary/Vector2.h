#pragma once;

#include <MathDefine.h>
#include <Types.h>
#include <MathUtils.h>
namespace math
{
	struct Vector2
	{
		explicit Vector2(f32 x = 0.0f, f32 y = 0.0f) :x(x), y(y)
		{
		}

		explicit Vector2(f32 data[2]) :x(data[0]), y(data[1])
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
		

		Vector2(const Vector2& source)
		{
			this->x = source.x;
			this->y = source.y;
		}

		inline Vector2& operator=(const Vector2& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			return *this;
		}

		inline Vector2& swap()
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

		inline f32& operator[](const int& index)
		{
			return data[index];
		}

		inline f32 length() const
		{
			return sqrt(this->x * this->x + this->y * this->y);
		}

		inline void normalize()
		{
			const f32 length = this->length();
			this->x /= length;
			this->y /= length;
		}

	};

	inline Vector2& operator+=(Vector2& lhs, const Vector2& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}

	inline Vector2& operator+=(Vector2& lhs, f32 scaler)
	{
		lhs.x += scaler;
		lhs.y += scaler;
		return lhs;
	}

	inline Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	inline Vector2& operator-=(Vector2& lhs, const Vector2& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}

	inline Vector2& operator-=(Vector2& lhs, f32 scaler)
	{
		lhs.x -= scaler;
		lhs.y -= scaler;
		return lhs;
	}

	inline Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	inline Vector2 operator-(const Vector2& rhs)
	{
		return Vector2(-rhs.x, -rhs.y);
	}

	inline Vector2& operator*=(Vector2& lhs, f32 scaler)
	{
		lhs.x *= scaler;
		lhs.y *= scaler;
		return lhs;
	}

	inline Vector2& operator*=(Vector2& lhs, const Vector2& rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		return lhs;
	}

	inline Vector2 operator*(f32 scaler, const Vector2& rhs)
	{
		return Vector2(scaler*rhs.x, scaler*rhs.y);
	}

	inline Vector2 operator*(const Vector2& lhs, f32 scaler)
	{
		return scaler * lhs;
	}

	inline Vector2 operator*(const Vector2& lhs, Vector2& rhs)
	{
		return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
	}

	inline Vector2& operator/=(Vector2& lhs, f32 scaler)
	{
		lhs.x /= scaler;
		lhs.y /= scaler;
		return lhs;
	}

	inline Vector2& operator/=(Vector2& lhs, const Vector2& rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		return lhs;
	}

	inline Vector2 operator/(const Vector2& lhs, f32 scaler)
	{
		return Vector2(lhs.x / scaler, lhs.y / scaler);
	}

	inline Vector2 operator/(const Vector2& lhs, Vector2& rhs)
	{
		return Vector2(lhs.x / rhs.x, lhs.y / rhs.y);
	}


	inline bool operator==(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x==rhs.x && lhs.y == rhs.y;
	}

	inline bool operator!=(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x != rhs.x || lhs.y != rhs.y;
	}

	inline f32 dot(const Vector2& lhs , const Vector2& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}


	inline f32 cross(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}


	inline f32 distance(const Vector2& from , const Vector2& to)
	{
		return sqrt(
			(to.x - from.x)*(to.x - from.x)
			+ (to.y - from.y)*(to.y - from.y)
			);
	}

	inline Vector2 normalize(const Vector2& source)
	{
		return Vector2(source) / source.length();
	}

	//Formula r = 2(d?n)n-d
	inline Vector2 reflect(const Vector2& source, const  Vector2& normal)
	{
		return (2 * normal * dot(source, normal)) - source;
	}

	//Forumula a.b/|a|*|b|
	inline f32 angle(const Vector2& lhs, const Vector2& rhs)
	{
		return MathUtils::acos(dot(lhs, rhs) / (lhs.length()*rhs.length()));
	}

	inline std::ostream& operator<<(std::ostream &out, Vector2& source)
	{
		// Since operator<< is a friend of the Point class, we can access
		// Point's members directly.
		out << "Vector2(" << source.x << ", " <<
			source.y << ", " << ")";
		return out;
	}
}








