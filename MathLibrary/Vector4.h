#pragma once
#pragma once
#include <MathDefine.h>
#include <Types.h>
#include "MathUtils.h"
#include "Vector3.h"
#include <iostream>

namespace math
{
	struct Vector4
	{
		Vector4(f32 x = 0.0f, f32 y = 0.0f, f32 z = 0.0f, f32 w = 0.0f) :x(x), y(y), z(z), w(w)
		{
		}

		explicit Vector4(f32 data[4]) :x(data[0]), y(data[1]), z(data[2]), w(data[3])
		{
		}

		union
		{
			f32 data[4];

			struct
			{
				f32 x;
				f32 y;
				f32 z;
				f32 w;
			};

			struct
			{
				f32 u;
				f32 v;
				f32 s;
				f32 r;

			};

			struct
			{
				f32 r;
				f32 g;
				f32 b;
				f32 a;
			};

		};

		Vector4(const Vector4& source)
		{
			this->x = source.x;
			this->y = source.y;
			this->z = source.z;
			this->w = source.w;
		}

		inline Vector4& operator=(const Vector4& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			this->w = rhs.w;
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
			return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
		}

		inline void normalize()
		{
			const f32 length = this->length();
			this->x /= length;
			this->y /= length;
			this->z /= length;
			this->w /= length;
		}

	};

	inline Vector4& operator+=(Vector4& lhs, const Vector4& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		lhs.w += rhs.w;
		return lhs;
	}

	inline Vector4& operator+=(Vector4& lhs, f32 scaler)
	{
		lhs.x += scaler;
		lhs.y += scaler;
		lhs.z += scaler;
		lhs.w += scaler;
		return lhs;
	}

	inline Vector4 operator+(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
	}

	inline Vector4& operator-=(Vector4& lhs, const Vector4& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		lhs.w -= rhs.w;
		return lhs;
	}

	inline Vector4& operator-=(Vector4& lhs, f32 scaler)
	{
		lhs.x -= scaler;
		lhs.y -= scaler;
		lhs.z -= scaler;
		lhs.w -= scaler;
		return lhs;
	}

	inline Vector4 operator-(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
	}

	inline Vector4 operator-(const Vector4& rhs)
	{
		return Vector4(-rhs.x, -rhs.y, -rhs.z, -rhs.w);
	}

	inline Vector4& operator*=(Vector4& lhs, const Vector4& rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		lhs.z *= rhs.z;
		lhs.w *= rhs.w;
		return lhs;
	}

	inline Vector4& operator*=(Vector4& lhs, f32 scaler)
	{
		lhs.x *= scaler;
		lhs.y *= scaler;
		lhs.z *= scaler;
		lhs.w *= scaler;
		return lhs;
	}

	inline Vector4 operator*(f32 scaler, const Vector4& rhs)
	{
		return Vector4(scaler*rhs.x, scaler*rhs.y, scaler*rhs.z, scaler*rhs.w);
	}

	inline Vector4 operator*(const Vector4& lhs, f32 scaler)
	{
		return scaler * lhs;
	}

	inline Vector4 operator*(const Vector4& lhs, Vector4& rhs)
	{
		return Vector4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
	}

	inline Vector4& operator/=(Vector4& lhs, const Vector4& rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		lhs.z /= rhs.z;
		lhs.w /= rhs.w;
		return lhs;
	}

	inline Vector4& operator/=(Vector4& lhs, f32 scaler)
	{
		lhs.x /= scaler;
		lhs.y /= scaler;
		lhs.z /= scaler;
		lhs.w /= scaler;
		return lhs;
	}

	inline Vector4 operator/(const Vector4& lhs, f32 scaler)
	{
		return Vector4(lhs.x / scaler, lhs.y / scaler, lhs.z / scaler, lhs.w / scaler);
	}

	inline Vector4 operator/(const Vector4& lhs, Vector4& rhs)
	{
		return Vector4(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
	}


	inline bool operator==(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z  && lhs.w == rhs.w;
	}

	inline bool operator!=(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z || lhs.w != rhs.w;
	}

	inline f32 dot(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}


	inline f32 distance(const Vector4& from, const Vector4& to)
	{
		return sqrt(
			(to.x - from.x)*(to.x - from.x)
			+ (to.y - from.y)*(to.y - from.y)
			+ (to.z - from.z)*(to.z - from.z)
			+ (to.w - from.w)*(to.w - from.w)
			);
	}

	inline Vector4 normalize(Vector4& source)
	{
		return Vector4(source) / source.length();
	}

	inline std::ostream& operator<<(std::ostream &out, Vector4& source)
	{
		out << "Vector4(" << source.x << ", " <<
			source.y << ", " <<
			source.z << "," <<
			source.w << ")";
		return out;
	}
}