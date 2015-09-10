#pragma once
#include <Types.h>
#include <Vector3.h>
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
			struct
			{
				Vector3 v;
				f32 w;
			};
		};

		Quaternion(Quaternion& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			this->w = rhs.w;
		}

		Quaternion():x(0),y(0),z(0),w(1)
		{

		}

		Quaternion(f32 x, f32 y, f32 z, f32 w) :x(x), y(y), z(z), w(w)
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

	public:
		inline f32 lengthSquare() const
		{
			return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
		}

		inline f32 length()
		{
			return sqrt(lengthSquare());
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

	//q*v* q-1
	//http://www.gamedev.net/topic/466725-quaternion-vector-product/
	//  v + 2w(q x v) + 2*(q x (q x v))

	inline Vector3 operator*(const Quaternion& lhs, const Vector3& rhs)
	{
		Vector3 qv = cross(lhs.v, rhs);
		Vector3 qqv = cross(lhs.v, qv);
		
		return rhs + 2 * lhs.w * qv + 2 * qqv;
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



	inline Quaternion operator/(const Quaternion& lhs, const f32 rhs)
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

	
	inline f32 dot(const Quaternion& lhs , const Quaternion& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	inline f32 cross(const Quaternion& lhs, const Quaternion& rhs)
	{

	}

	inline Quaternion conjugate(const Quaternion& source)
	{
		return Quaternion(-source.x, -source.y, -source.z, source.w);
	}

	inline Quaternion inverse(const Quaternion& source)
	{
		return conjugate(source) / source.lengthSquare();
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
