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

	inline Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs)
	{
		Quaternion result;
		result.x = lhs.x + rhs.x;
		result.y = lhs.y + rhs.y;
		result.z = lhs.z + rhs.z;
		result.w = lhs.w + rhs.w;

		return result;
	}


	inline Quaternion& operator+=(Quaternion& lhs, const Quaternion& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		lhs.w += rhs.w;
		return lhs;
	}


	inline Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs)
	{
		Quaternion result;
		result.x = lhs.x - rhs.x;
		result.y = lhs.y - rhs.y;
		result.z = lhs.z - rhs.z;
		result.w = lhs.w - rhs.w;
		return result;
	}

	inline Quaternion& operator-(Quaternion& rhs)//more like x= -y;
	{
		rhs.x = -rhs.x;
		rhs.y = -rhs.y;
		rhs.z = -rhs.z;
		rhs.w = -rhs.w;
		return rhs;
	}


	inline Quaternion& operator-=(Quaternion& lhs, const Quaternion& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		lhs.w -= rhs.w;

		return lhs;
	}

	//http://www.mathworks.com/help/aeroblks/quaternionmultiplication.html
	inline Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs)
	{
		Quaternion result;

		result.x = rhs.w * lhs.x + rhs.x * lhs.w - rhs.y * lhs.z + rhs.z * lhs.y;
		result.y = rhs.w * lhs.y + rhs.x * lhs.z + rhs.y * lhs.w - rhs.z * lhs.x;
		result.z = rhs.w * lhs.z - rhs.x * lhs.y + rhs.y * lhs.x + rhs.z * lhs.w;
		result.w = rhs.w * lhs.w - rhs.x * lhs.x - rhs.y * lhs.y - rhs.z * lhs.z;

		return result;
	}


	inline Quaternion& operator*(const Quaternion& lhs, const Vector4& rhs)
	{

	}

	inline Quaternion operator*(const Quaternion& lhs, const f32 rhs)
	{
		Quaternion result;

		result.x = lhs.x * rhs;
		result.y = lhs.y * rhs;
		result.z = lhs.z * rhs;
		result.w = lhs.w * rhs;

		return result;
	}


	inline Quaternion& operator/(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	inline Quaternion& operator/=(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	inline Quaternion& operator/(const Quaternion& lhs, const f32 rhs)
	{
		Quaternion result;

		result.x = lhs.x / rhs;
		result.y = lhs.y / rhs;
		result.z = lhs.z / rhs;
		result.w = lhs.w / rhs;

		return result;
	}

	inline bool operator==(const Quaternion& lhs, const Quaternion& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y &&lhs.z == rhs.z &&lhs.w == rhs.w;
	}

	inline bool operator!=(const Quaternion& lhs, const Quaternion& rhs)
	{
		return !(lhs == rhs);
	}

	
	inline f32 lengthSquare(const Quaternion& source)
	{
		return source.x * source.x + source.y * source.y + source.z * source.z + source.w * source.w;
	}

	inline f32 length(const Quaternion& source)
	{
		return sqrt(lengthSquare(source));
	}

	inline f32 dot(const Quaternion& lhs , const Quaternion& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
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

	inline Quaternion slerp(const Quaternion& from , const Quaternion& to , f32 dt)
	{

	}

}
