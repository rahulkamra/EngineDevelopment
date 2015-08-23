#pragma once
#include <MathDefine.h>
#include <Types.h>
#include "MathUtils.h"

namespace math
{
	struct Vector3D
	{
		explicit Vector3D(f32 x = 0.0f, f32 y = 0.0f, f32 z = 0.0f) :x(x), y(y), z(z)
		{
		}

		explicit Vector3D(f32 data[3]) :x(data[0]), y(data[1]), z(data[2])
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

		Vector3D(const Vector3D& source)
		{
			this->x = source.x;
			this->y = source.y;
			this->z = source.z;
		}

		inline Vector3D& operator=(const Vector3D& rhs)
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

	inline Vector3D& operator+=(Vector3D& lhs, const Vector3D& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		return lhs;
	}

	inline Vector3D& operator+=(Vector3D& lhs, f32 scaler)
	{
		lhs.x += scaler;
		lhs.y += scaler;
		lhs.z += scaler;
		return lhs;
	}

	inline Vector3D& operator-=(Vector3D& lhs, const Vector3D& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		return lhs;
	}

	inline Vector3D& operator-=(Vector3D& lhs, f32 scaler)
	{
		lhs.x -= scaler;
		lhs.y -= scaler;
		lhs.z -= scaler;
		return lhs;
	}

	inline Vector3D& operator*=(Vector3D& lhs, const Vector3D& rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		lhs.z *= rhs.z;
		return lhs;
	}

	inline Vector3D& operator*=(Vector3D& lhs, f32 scaler)
	{
		lhs.x *= scaler;
		lhs.y *= scaler;
		lhs.z *= scaler;
		return lhs;
	}

	inline Vector3D& operator/=(Vector3D& lhs, const Vector3D& rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		lhs.z /= rhs.z;
		return lhs;
	}

	inline Vector3D& operator/=(Vector3D& lhs, f32 scaler)
	{
		lhs.x /= scaler;
		lhs.y /= scaler;
		lhs.z /= scaler;
		return lhs;
	}

	inline Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}


	inline Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	inline Vector3D operator-(const Vector3D& rhs)
	{
		return Vector3D(-rhs.x, -rhs.y, -rhs.z);
	}

	inline Vector3D operator*(f32 scaler, const Vector3D& rhs)
	{
		return Vector3D(scaler*rhs.x, scaler*rhs.y, scaler*rhs.z);
	}

	inline Vector3D operator*(const Vector3D& lhs, f32 scaler)
	{
		return scaler * lhs;
	}

	inline Vector3D operator*(const Vector3D& lhs, Vector3D& rhs)
	{
		return Vector3D(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
	}


	inline Vector3D operator/(const Vector3D& lhs, f32 scaler)
	{
		return Vector3D(lhs.x / scaler, lhs.y / scaler, lhs.z / scaler);
	}

	inline Vector3D operator/(const Vector3D& lhs, Vector3D& rhs)
	{
		return Vector3D(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
	}


	inline bool operator==(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	inline bool operator!=(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z;
	}

	inline f32 dot(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}


	inline Vector3D cross(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D
			(
				lhs.y *  rhs.z - lhs.z * rhs.y ,
				lhs.z * rhs.x - lhs.x * rhs.z , 
				lhs.x * rhs.y - lhs.y * rhs.x
			);
	}

	inline f32 distance(const Vector3D& from, const Vector3D& to)
	{
		return sqrt(
			(to.x - from.x)*(to.x - from.x)
		  + (to.y - from.y)*(to.y - from.y)
		  + (to.z - from.z)*(to.z - from.z)
			);
	}

	inline Vector3D normalize(Vector3D& source)
	{
		return Vector3D(source) / source.length();
	}

	//Formula r = 2(d?n)n-d
	inline Vector3D reflect(Vector3D& source, Vector3D& normal)
	{
		return (2 * normal * dot(source, normal)) - source;
	}

	//Forumula a.b/|a|*|b|
	inline f32 angle(Vector3D& lhs, Vector3D& rhs)
	{
		return MathUtils::acos(dot(lhs, rhs) / (lhs.length()*rhs.length()));
	}

	inline std::ostream& operator<<(std::ostream &out, Vector3D& source)
	{
		// Since operator<< is a friend of the Point class, we can access
		// Point's members directly.
		out << "Vector3D(" << source.x << ", " <<
			source.y << ", " <<
			source.z << ")";
		return out;
	}
}