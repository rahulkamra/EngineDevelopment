	#pragma once
	#include <MathDefine.h>
namespace math
{
	struct Vector3D
	{
		explicit Vector3D(efloat x = 0.0f, efloat y = 0.0f, efloat z = 0.0f) :x(x), y(y), z(z)
		{

		}

		efloat x, y, z;

		inline efloat dot(Vector3D* rhs)
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

	inline Vector3D operator*(efloat scaler, const Vector3D& rhs)
	{
		return Vector3D(scaler*rhs.x, scaler*rhs.y , scaler*rhs.z);
	}

	inline Vector3D operator*(const Vector3D& lhs, efloat scaler)
	{
		return scaler * lhs;
	}

	inline Vector3D operator/(const Vector3D& lhs, efloat scaler)
	{
		return Vector3D(lhs.x / scaler, lhs.y / scaler , lhs.z / scaler);
	}
}