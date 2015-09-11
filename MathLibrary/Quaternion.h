#pragma once
#include <Types.h>
#include <Vector3.h>
#include <Vector4.h>
#include <Matrix4.h>
#include <EulerAngles.h>
#include <AxisAngle.h>
#include <MathUtils.h>
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

	inline Quaternion conjugate(const Quaternion& source)
	{
		return Quaternion(-source.x, -source.y, -source.z, source.w);
	}

	inline Quaternion inverse(const Quaternion& source)
	{
		return conjugate(source) / source.lengthSquare();
	}

	inline f32 lengthSquare(const Quaternion& source)
	{
		return source.x * source.x + source.y * source.y + source.z * source.z + source.w * source.w;
	}


	inline f32 length(const Quaternion& source)
	{
		return sqrt(lengthSquare(source));
	}


	inline Quaternion normalize(const Quaternion& source)
	{
		return source / length(source);
	}


	//http://www.euclideanspace.com/maths/geometry/rotations/conversions/eulerToQuaternion/index.htm
	/*
	*/
	inline Quaternion eulerAnglesToQuaternion(const EulerAngles eulerAngles)
	{
		f32 c1 = math::cos(eulerAngles.heading / 2);
		f32 c2 = math::cos(eulerAngles.attitude / 2);
		f32 c3 = math::cos(eulerAngles.bank / 2);

		f32 s1 = math::sin(eulerAngles.heading / 2);
		f32 s2 = math::sin(eulerAngles.attitude / 2);
		f32 s3 = math::sin(eulerAngles.bank / 2);

		return Quaternion(
			s1*s2*c3 + c1*c2*s3,
			s1*c2*c3 + c1*s2*s3,
			c1*s2*c3 - s1*c2*s3,
			c1*c2*c3 - s1*s2*s3);
	}

	//http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/
	/*
	*/
	inline EulerAngles quaternionToEulerAngles(const Quaternion& source)
	{
		EulerAngles result;
		f32 xy = source.x*source.y;
		f32 zw = source.z*source.w;
		f32 singularityTest = xy + zw;

		if (singularityTest > 0.499f)
		{
			result.heading = 2 * atan2(source.x , source.w);
			result.attitude = MATH_PI_2;
			result.bank = 0;
			return result;
		}
		else if (singularityTest < -0.499f)
		{
			result.heading = -2 * atan2(source.x, source.w);
			result.attitude = -MATH_PI_2;
			result.bank = 0;
			return result;
		}

		//normal case

		f32 xx = source.x * source.x;
		f32 yy = source.y * source.y;
		f32 zz = source.z * source.z;

		result.heading = atan2(2 * source.y*source.w - 2 * source.x*source.z, 1 - 2*yy - 2*zz);
		result.attitude = asin(2 * source.x*source.y + 2 * source.z*source.w);
		result.bank = atan2(2 * source.x*source.w - 2 * source.y*source.z, 1 - 2*xx - 2*zz);
		return result;
	}
	//http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
	/*
	*/
	inline Quaternion matrix4ToQuaternion(const Matrix4& source)
	{
		Quaternion result;
		f32 tr = source[0][0] + source[1][1] + source[2][2];
		f32 s = 0;
		if (tr > 0)
		{
			s = sqrt(tr + 1.0f) * 2;
			result.x = (source[1][2] - source[2][1]) / s;
			result.y = (source[2][0] - source[0][2]) / s;
			result.z = (source[0][1] - source[1][0]) / s;
			result.w = 0.25f * s;
		}
		else if ((source[0][0] > source[1][1]) && (source[0][0] > source[2][2]))
		{
			s = sqrt(1.0f + source[0][0] - source[1][1] - source[2][2]) * 2.0f;
			result.x = 0.25f * s;
			result.y = (source[1][0] + source[0][1]) / s;
			result.z = (source[2][0] + source[0][2]) / s;
			result.w = (source[1][2] - source[2][1]) / s;
		}
		else if (source[1][1] > source[2][2])
		{
			s = sqrt(1.0f + source[1][1] - source[0][0] - source[2][2]) * 2.0f;
			result.x = (source[1][0] + source[0][1]) / s;
			result.y = 0.25f * s;
			result.z = (source[1][2] + source[2][1]) / s;
			result.w = (source[2][0] - source[0][2]) / s;
		}
		else
		{
			s = sqrt(1.0f + source[2][2] - source[0][0] - source[1][1]) * 2.0f;
			result.x = (source[2][0] + source[0][2]) / s;
			result.y = (source[1][2] + source[2][1]) / s;
			result.z = 0.25f * s;
			result.w = (source[0][1] - source[1][0]) / s;
		}
		return result;

	}

	inline Matrix4 quaternionToMatrix4(const Quaternion& source)
	{
		f32 xx = source.x * source.x;
		f32 yy = source.y * source.y;
		f32 zz = source.z * source.z;

		f32 xy2 = 2.0f * source.x * source.y;
		f32 yz2 = 2.0f * source.y * source.z;
		f32 zw2 = 2.0f * source.z * source.w;
		f32 yw2 = 2.0f * source.y * source.w;
		f32 xw2 = 2.0f * source.x * source.w;
		f32 xz2 = 2.0f * source.x * source.z;

		Matrix4 result;

		result[0][0] = 1.0f - 2.0f * (yy + zz);
		result[0][1] = xy2 + zw2;
		result[0][2] = xz2 - yw2;

		result[1][0] = xy2 - zw2;
		result[1][1] = 1.0f - 2.0f * (xx + zz);;
		result[1][2] = yz2 + xw2;

		result[2][0] = xz2 + yw2;
		result[2][1] = yz2 - xw2;
		result[2][2] = 1.0f - 2.0f * (xx + yy);

		return result;
	}

	//http://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToQuaternion/
	/*
	*/
	inline Quaternion axisAngleToQuaternion(const AxisAngle& axisAngle)
	{
		f32 sin = math::sin(axisAngle.angle / 2);
		f32 cos = math::sin(axisAngle.angle / 2);

		return Quaternion(axisAngle.axis.x*sin, axisAngle.axis.y*sin, axisAngle.axis.z*sin, cos);
	}

	//http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToAngle/index.htm
	/*
	*/
	inline AxisAngle quaternionToAxisAngle(Quaternion& source)
	{

		if (source.x > 1)
			source.normalize();

		f32 angle = 2 * acos(source.w);
		f32 mult = 1/sqrt(1 - source.w * source.w);

		AxisAngle result;
		result.angle = angle;
		if (mult < 0.001)
		{
			result.axis.x = source.x;
			result.axis.y = source.y;
			result.axis.z = source.z;
		}
		else
		{
			result.axis.x = source.x * mult;
			result.axis.y = source.y * mult;
			result.axis.z = source.z * mult;
		}
		return result;
	}

	inline Quaternion slerp(const Quaternion& from , const Quaternion& to , f32 dt)
	{

	}

	inline std::ostream& operator<<(std::ostream &out, Quaternion& source)
	{
		out << "Quaternion(" << source.x << ", " <<
			source.y << ", " <<
			source.z << "," <<
			source.w << ")";
		return out;
	}
}
