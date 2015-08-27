#pragma once
#include <MathDefine.h>
#include <Vector3.h>
#include <math.h>
#include <array>

namespace math
{
	struct Matrix3
	{

		union
		{
			struct
			{
				Vector3 x, y,z;
			};

			Vector3 vectors[3];
		};


		Matrix3(const Matrix3& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
		}

		explicit Matrix3() :
			x(1, 0, 0),
			y(0, 1, 0),
			z(0, 0, 1)
		{
		}

		explicit Matrix3(const Vector3& v1, const Vector3& v2, const Vector3& v3) :
			x(v1),
			y(v2),
			z(v3)
		{

		}

		//we need const as well as non cost operators.
		inline const Vector3& operator[](usize index) const { return vectors[index]; }
		inline Vector3& operator[](usize index) { return vectors[index]; }

		inline Matrix3& operator=(const Matrix3& rhs)
		{
			for (usize row = 0; row < 3; row++)
			{
				(*this)[row] = rhs[row];
			}

			return *this;
		}


	};


	inline Matrix3 operator+(const Matrix3& lhs, const Matrix3& rhs)
	{
		Matrix3 ret;
		for (usize row = 0; row < 3; row++)
		{
			ret[row] = lhs[row] + rhs[row];
		}

		return ret;
	}


	inline Matrix3& operator+=(Matrix3& lhs, const Matrix3& rhs)
	{
		for (usize row = 0; row < 3; row++)
		{
			lhs[row] += rhs[row];
		}
		return lhs;
	}

	inline Matrix3 operator-(const Matrix3& lhs, const Matrix3& rhs)
	{
		Matrix3 ret;
		for (usize row = 0; row < 3; row++)
		{
			ret[row] = lhs[row] - rhs[row];
		}
		return ret;
	}

	inline Matrix3& operator-=(Matrix3& lhs, const Matrix3& rhs)
	{
		for (usize row = 0; row < 3; row++)
		{
			lhs[row] -= rhs[row];
		}
		return lhs;
	}

	inline Matrix3 operator*(const Matrix3& lhs, const f32& rhs)
	{
		Matrix3 ret;
		for (usize row = 0; row < 3; row++)
		{
			ret[row] = lhs[row] * rhs;
		}

		return ret;
	}

	inline Matrix3 operator*(const Matrix3& lhs, const Matrix3& rhs)
	{
		Matrix3 result;
		result[0] = lhs[0] * rhs[0][0] + lhs[1] * rhs[0][1] + lhs[2] * rhs[0][2];
		result[1] = lhs[0] * rhs[1][0] + lhs[1] * rhs[1][1] + lhs[2] * rhs[1][2];
		result[2] = lhs[0] * rhs[2][0] + lhs[1] * rhs[2][1] + lhs[2] * rhs[2][2];
		return result;
	}


	inline Vector3 const operator*(const Matrix3& lhs, const Vector3& rhs)
	{
		return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
	}

	inline Matrix3 operator/(const Matrix3& lhs, const f32& rhs)
	{
		Matrix3 ret;
		for (usize row = 0; row < 3; row++)
		{
			ret[row] = lhs[row] / rhs;
		}

		return ret;
	}

	inline Matrix3& operator/=(Matrix3& lhs, const f32& rhs)
	{
		Matrix3 ret;
		for (usize row = 0; row < 3; row++)
		{
			lhs[row] /= rhs;
		}

		return ret;
	}

	inline bool operator==(const Matrix3& lhs, const Matrix3& rhs)
	{
		for (usize i = 0; i < 3; i++)
		{
			if (lhs[i] != rhs[i])
			{
				return false;
			}
		}
		return true;
	}


	inline bool operator!=(const Matrix3& lhs, const Matrix3& rhs)
	{
		for (usize i = 0; i < 3; i++)
		{
			if (lhs[i] != rhs[i])
			{
				return true;
			}
		}
		return false;
	}


	inline Matrix3 transpose(const Matrix3& source)
	{
		Matrix3 result;
		for (usize i = 0; i < 3; i++)
		{
			for (usize j = 0; j < 3; j++)
				result[i][j] = source[j][i];
		}
	}

	inline f32 determinant(const Matrix3& source)
	{
		return source[0][0] * (source[1][1] * source[2][2] - source[2][1] * source[1][2]) -
			source[1][0] * (source[0][1] * source[2][2] - source[0][2] * source[2][1]) +
			source[2][0] * (source[0][1] * source[1][2] - source[0][2] * source[1][1]);	
	}

	inline Matrix3 inverse(const Matrix3& source)
	{
		Matrix3 result;
		return result;
	}

}
