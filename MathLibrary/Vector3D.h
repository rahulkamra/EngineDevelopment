#pragma once
#include <MathDefine.h>
#include <Types.h>
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


		inline f32 length() const
		{
			return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		}


		inline Vector3D& operator+=(const Vector3D& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			return *this;
		}

		inline Vector3D& operator+=(f32 scaler)
		{
			this->x += scaler;
			this->y += scaler;
			this->z += scaler;
			return *this;
		}

		inline Vector3D& operator-=(const Vector3D& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			return *this;
		}

		inline Vector3D& operator-=(f32 scaler)
		{
			this->x -= scaler;
			this->y -= scaler;
			this->z -= scaler;
			return *this;
		}

		//hadamard product
		inline Vector3D& operator*=(const Vector3D& rhs)
		{
			this->x *= rhs.x;
			this->y *= rhs.y;
			this->z *= rhs.z;
			return *this;
		}

		inline Vector3D& operator*=(f32 scaler)
		{
			this->x *= scaler;
			this->y *= scaler;
			this->z *= scaler;
			return *this;
		}

		inline Vector3D& operator/=(const Vector3D& rhs)
		{
			this->x /= rhs.x;
			this->y /= rhs.y;
			this->z /= rhs.z;
			return *this;
		}

		inline Vector3D& operator/=(f32 scaler)
		{
			this->x /= scaler;
			this->y /= scaler;
			this->z /= scaler;
			return *this;
		}

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

		//inline f32 distance(const Vector3D& rhs) const
		//{
		//	return sqrt((rhs.x - this->x)*(rhs.x - this->x) - ((rhs.x - this->x)*(rhs.x - this->x)));
		//}
	};

	inline Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	inline Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}


	inline Vector3D operator*(f32 scaler, const Vector3D& rhs)
	{
		return Vector3D(scaler*rhs.x, scaler*rhs.y, scaler*rhs.z);
	}

	inline Vector3D operator*(const Vector3D& lhs, f32 scaler)
	{
		return scaler * lhs;
	}


	inline Vector3D operator/(const Vector3D& lhs, f32 scaler)
	{
		return Vector3D(lhs.x / scaler, lhs.y / scaler, lhs.z / scaler);
	}

	inline bool operator==(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	inline bool operator!=(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z;
	}

	//inline f32 dot(const Vector3D& lhs, const Vector3D& rhs)
	//{
	//	return lhs.x * rhs.x + lhs.y * rhs.y;
	//}


	//inline f32 cross(const Vector3D& lhs, const Vector3D& rhs)
	//{
	//	return lhs.x * rhs.y - lhs.y * rhs.x;
	//}

}