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

		f32 x, y, z;

		inline f32 dot(Vector3D* rhs)
		{
			return this->x * rhs->x + this->y * rhs->y + this->z * rhs->z ;
		}

		inline Vector3D& operator+=(const Vector3D& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			return *this;
		}


		inline Vector3D& operator-=(const Vector3D& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			return *this;
		}

		//copy Construtor
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


	};



	inline Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D(lhs.x + rhs.x, lhs.y + rhs.y,lhs.z + rhs.z);
	}

	inline Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D(lhs.x - rhs.x, lhs.y - rhs.y , lhs.z- rhs.z);
	}

	inline Vector3D operator*(f32 scaler, const Vector3D& rhs)
	{
		return Vector3D(scaler*rhs.x, scaler*rhs.y , scaler*rhs.z);
	}

	inline Vector3D operator*(const Vector3D& lhs, f32 scaler)
	{
		return scaler * lhs;
	}

	inline Vector3D operator/(const Vector3D& lhs, f32 scaler)
	{
		return Vector3D(lhs.x / scaler, lhs.y / scaler , lhs.z / scaler);
	}
}