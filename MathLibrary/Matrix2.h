#pragma once
#include <MathDefine.h>
#include <Vector2.h>
#include <math.h>
#include <array>

namespace math
{
	struct Matrix2
	{

		union
		{
			struct
			{
				Vector2 x, y;
			};

			Vector2 vectors[2];
		};


		Matrix2(const Matrix2& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
		}

		explicit Matrix2() :
			x(1, 0),
			y(0, 1)
		{
		}

		explicit Matrix2(const Vector2& v1, const Vector2& v2) :
			x(v1),
			y(v2)
		{

		}


		inline static Matrix2 createRotateMatrix(const f32 angle)
		{
			f32 cosTheta = cos(angle);
			f32 sinTheta = sin(angle);
			return Matrix2
				(
					Vector2{ cosTheta,-sinTheta },
					Vector2{ sinTheta,cosTheta }
			);
		}


		//we need const as well as non cost operators.
		inline const Vector2& operator[](usize index) const { return vectors[index]; }
		inline Vector2& operator[](usize index) { return vectors[index]; }

		inline Matrix2& operator=(const Matrix2& rhs)
		{
			for (usize row = 0; row < 2; row++)
			{
				(*this)[row] = rhs[row];
			}

			return *this;
		}


	};


	inline Matrix2 operator+(const Matrix2& lhs, const Matrix2& rhs)
	{
		Matrix2 ret;
		for (usize row = 0; row < 2; row++)
		{
			ret[row] = lhs[row] + rhs[row];
		}

		return ret;
	}


	inline Matrix2& operator+=(Matrix2& lhs, const Matrix2& rhs)
	{
		for (usize row = 0; row < 2; row++)
		{
			lhs[row] += rhs[row];
		}
		return lhs;
	}

	inline Matrix2 operator-(const Matrix2& lhs, const Matrix2& rhs)
	{
		Matrix2 ret;
		for (usize row = 0; row < 2; row++)
		{
			ret[row] = lhs[row] - rhs[row];
		}
		return ret;
	}

	inline Matrix2& operator-=(Matrix2& lhs, const Matrix2& rhs)
	{
		for (usize row = 0; row < 2; row++)
		{
			lhs[row] -= rhs[row];
		}
		return lhs;
	}

	inline Matrix2 operator*(const Matrix2& lhs, const f32& rhs)
	{
		Matrix2 ret;
		for (usize row = 0; row < 2; row++)
		{
			ret[row] = lhs[row] * rhs;
		}

		return ret;
	}

	inline Matrix2 operator*(const Matrix2& lhs, const Matrix2& rhs)
	{
		Matrix2 result;

		result[0][0] = rhs[0][0] * lhs[0][0] + rhs[0][1] * lhs[1][0];
		result[0][1] = rhs[0][0] * lhs[0][1] + rhs[0][1] * lhs[1][1];

		result[1][0] = rhs[1][0] * lhs[0][0] + rhs[1][1] * lhs[1][0];
		result[1][1] = rhs[1][0] * lhs[0][1] + rhs[1][1] * lhs[1][1];

		return result;
	}


	inline Vector2 const operator*(const Matrix2& lhs, const Vector2& rhs)
	{
		return lhs[0] * rhs.x + lhs[1] * rhs.y;
	}

	inline Matrix2 operator/(const Matrix2& lhs, const f32& rhs)
	{
		Matrix2 ret;
		for (usize row = 0; row < 2; row++)
		{
			ret[row] = lhs[row] / rhs;
		}

		return ret;
	}

	inline Matrix2& operator/=(Matrix2& lhs, const f32& rhs)
	{
		Matrix2 ret;
		for (usize row = 0; row < 2; row++)
		{
			lhs[row] /= rhs;
		}

		return ret;
	}

	inline bool operator==(const Matrix2& lhs, const Matrix2& rhs)
	{
		for (usize i = 0; i < 2; i++)
		{
			if (lhs[i] != rhs[i])
			{
				return false;
			}
		}
		return true;
	}


	inline bool operator!=(const Matrix2& lhs, const Matrix2& rhs)
	{
		for (usize i = 0; i < 2; i++)
		{
			if (lhs[i] != rhs[i])
			{
				return true;
			}
		}
		return false;
	}


	inline Matrix2 transpose(const Matrix2& source)
	{
		Matrix2 result;
		for (usize i = 0; i < 2; i++)
		{
			for (usize j = 0; j < 2; j++)
				result[i][j] = source[j][i];
		}
	}

	inline f32 determinant(const Matrix2& source)
	{
		return source[0][0] * source[1][1] - source[1][0] * source[0][1];
	}

	inline Matrix2 inverse(const Matrix2& source)
	{
		Matrix2 result;
		result[0][0] = source[1][1];
		result[1][1] = source[0][0];

		result[1][0] = -source[1][0];
		result[0][1] = -source[0][1];

		result /= determinant(source);
		return result;
	}
	
}
