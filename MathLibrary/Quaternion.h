#pragma once
#include <Types.h>
#include <Vector4.h>
#include <Matrix4.h>
#include <EulerAngles.h>
namespace math
{
	struct Quaternion
	{
		union 
		{
			f32 data[4];
			struct 
			{
				f32 x, y, z, w;
			};
		};

		Quaternion(const Quaternion& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			this->w = rhs.w;
		}

		Quaternion():x(0),y(0),z(0),w(1)
		{

		}

		inline f32 operator[](usize index)
		{
			return this->data[index];
		}

		inline const f32 operator[](usize index) const
		{
			return this->data[index];
		}

		inline Quaternion& operator=(const Quaternion& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			this->w = rhs.w;

			return *this;
		}

	};

	inline Quaternion& operator+(const Quaternion& lhs, const Quaternion& rhs)
	{

	}


	inline Quaternion& operator+=(const Quaternion& lhs, const Quaternion& rhs)
	{

	}


	inline Quaternion& operator-(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	inline Quaternion& operator-(const Quaternion& rhs)
	{//more like x= -y;

	}


	inline Quaternion& operator-=(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	inline Quaternion& operator*(const Quaternion& lhs, const Quaternion& rhs)
	{

	}


	inline Quaternion& operator*(const Quaternion& lhs, const Vector4& rhs)
	{

	}

	inline Quaternion& operator*(const Quaternion& lhs, const f32 rhs)
	{

	}


	inline Quaternion& operator/(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	inline Quaternion& operator/=(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	inline Quaternion& operator/(const Quaternion& lhs, const f32 rhs)
	{

	}

	inline bool operator==(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	inline bool operator!=(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	
	inline f32 lengthSquare(const Quaternion& source)
	{

	}

	inline f32 length(const Quaternion& source)
	{

	}

	inline f32 dot(const Quaternion& lhs , const Quaternion& rhs)
	{

	}

	inline f32 cross(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	inline Quaternion conjugate(const Quaternion& source)
	{

	}

	inline Quaternion normalize(const Quaternion& source)
	{

	}


	inline Quaternion axisAngleToQuaternion(const Vector3 axisAngle, f32 angleinRadians)
	{

	}

	inline Quaternion eulerAnglesToQuaternion(const EulerAngles eulerAngles)
	{

	}

	inline Quaternion matrix4ToQuaternion(const Matrix4& source)
	{

	}

	inline Matrix4 matrix4ToQuaternion(const Quaternion& source)
	{

	}

	inline Vector3 quaternionToAxis(const Quaternion& source)
	{

	}

	inline Vector3 quaternionToAngle(const Quaternion& source)
	{

	}


}
