#pragma once
#include <MathDefine.h>
#include <Types.h>
#include "MathUtils.h"
#include <iostream>

namespace math
{
	struct Vector3
	{
		explicit Vector3(f32 x = 0.0f, f32 y = 0.0f, f32 z = 0.0f) :x(x), y(y), z(z)
		{
		}

		explicit Vector3(f32 data[3]) :x(data[0]), y(data[1]), z(data[2])
		{
		}

		union
		{
			f32 data[3];

			struct
			{
				f32 x;
				f32 y;
				f32 z;
			};

			struct
			{
				f32 u;
				f32 v;
				f32 s;
				
			};

			struct
			{
				f32 r;
				f32 g;
				f32 b;
				
			};

		};

		Vector3(const Vector3& source)
		{
			this->x = source.x;
			this->y = source.y;
			this->z = source.z;
		}

		inline Vector3& operator=(const Vector3& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
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
			return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		}

		inline void normalize()
		{
			const f32 length = this->length();
			this->x /= length;
			this->y /= length;
			this->z /= length;
		}

	};

	inline Vector3& operator+=(Vector3& lhs, const Vector3& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		return lhs;
	}

	inline Vector3& operator+=(Vector3& lhs, f32 scaler)
	{
		lhs.x += scaler;
		lhs.y += scaler;
		lhs.z += scaler;
		return lhs;
	}

	inline Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	inline Vector3& operator-=(Vector3& lhs, const Vector3& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		return lhs;
	}

	inline Vector3& operator-=(Vector3& lhs, f32 scaler)
	{
		lhs.x -= scaler;
		lhs.y -= scaler;
		lhs.z -= scaler;
		return lhs;
	}

	inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	inline Vector3 operator-(const Vector3& rhs)
	{
		return Vector3(-rhs.x, -rhs.y, -rhs.z);
	}

	inline Vector3& operator*=(Vector3& lhs, const Vector3& rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		lhs.z *= rhs.z;
		return lhs;
	}

	inline Vector3& operator*=(Vector3& lhs, f32 scaler)
	{
		lhs.x *= scaler;
		lhs.y *= scaler;
		lhs.z *= scaler;
		return lhs;
	}

	inline Vector3 operator*(f32 scaler, const Vector3& rhs)
	{
		return Vector3(scaler*rhs.x, scaler*rhs.y, scaler*rhs.z);
	}

	inline Vector3 operator*(const Vector3& lhs, f32 scaler)
	{
		return scaler * lhs;
	}

	inline Vector3 operator*(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
	}

	inline Vector3& operator/=(Vector3& lhs, const Vector3& rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		lhs.z /= rhs.z;
		return lhs;
	}

	inline Vector3& operator/=(Vector3& lhs, f32 scaler)
	{
		lhs.x /= scaler;
		lhs.y /= scaler;
		lhs.z /= scaler;
		return lhs;
	}

	inline Vector3 operator/(const Vector3& lhs, f32 scaler)
	{
		return Vector3(lhs.x / scaler, lhs.y / scaler, lhs.z / scaler);
	}

	inline Vector3 operator/(const Vector3& lhs, Vector3& rhs)
	{
		return Vector3(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
	}


	inline bool operator==(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	inline bool operator!=(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z;
	}

	inline f32 dot(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}


	inline Vector3 cross(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3
			(
				lhs.y *  rhs.z - lhs.z * rhs.y ,
				lhs.z * rhs.x - lhs.x * rhs.z , 
				lhs.x * rhs.y - lhs.y * rhs.x
			);
	}

	inline f32 distance(const Vector3& from, const Vector3& to)
	{
		return sqrt(
			(to.x - from.x)*(to.x - from.x)
		  + (to.y - from.y)*(to.y - from.y)
		  + (to.z - from.z)*(to.z - from.z)
			);
	}

	inline Vector3 normalize(Vector3& source)
	{
		return Vector3(source) / source.length();
	}

	//Formula r = 2(d?n)n-d
	inline Vector3 reflect(Vector3& source, Vector3& normal)
	{
		return (2 * normal * dot(source, normal)) - source;
	}

	//Forumula a.b/|a|*|b|
	inline f32 angle(Vector3& lhs, Vector3& rhs)
	{
		return MathUtils::acos(dot(lhs, rhs) / (lhs.length()*rhs.length()));
	}

	inline std::ostream& operator<<(std::ostream &out, Vector3& source)
	{
		// Since operator<< is a friend of the Point class, we can access
		// Point's members directly.
		out << "Vector3(" << source.x << ", " <<
			source.y << ", " <<
			source.z << ")";
		return out;
	}
}