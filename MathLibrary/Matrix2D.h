#pragma once
#include <MathDefine.h>
#include <Vector2D.h>
#include <math.h>
#include <array>

namespace math
{
	struct Matrix2D
	{

		union
		{
			struct
			{
				Vector2D x, y;
			};

			Vector2D vectors[2];
		};


		Matrix2D(const Matrix2D& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
		}

		explicit Matrix2D() :
			x(1, 0),
			y(0, 1)
		{
		}

		explicit Matrix2D(const Vector2D& v1, const Vector2D& v2) :
			x(v1),
			y(v2)
		{

		}


		inline static Matrix2D createRotateMatrix(const f32 angle)
		{
			f32 cosTheta = cos(angle);
			f32 sinTheta = sin(angle);
			return Matrix2D
				(
					Vector2D{ cosTheta,-sinTheta },
					Vector2D{ sinTheta,cosTheta }
			);
		}


		//we need const as well as non cost operators.
		inline const Vector2D& operator[](usize index) const { return vectors[index]; }
		inline Vector2D& operator[](usize index) { return vectors[index]; }

		inline Matrix2D& operator=(const Matrix2D& rhs)
		{
			for (usize row = 0; row < 2; row++)
			{
				(*this)[row] = rhs[row];
			}

			return *this;
		}


	};


	inline Matrix2D operator+(const Matrix2D& lhs, const Matrix2D& rhs)
	{
		Matrix2D ret;
		for (usize row = 0; row < 2; row++)
		{
			ret[row] = lhs[row] + rhs[row];
		}

		return ret;
	}


	inline Matrix2D& operator+=(Matrix2D& lhs, const Matrix2D& rhs)
	{
		for (usize row = 0; row < 2; row++)
		{
			lhs[row] += rhs[row];
		}
		return lhs;
	}

	inline Matrix2D operator-(const Matrix2D& lhs, const Matrix2D& rhs)
	{
		Matrix2D ret;
		for (usize row = 0; row < 2; row++)
		{
			ret[row] = lhs[row] - rhs[row];
		}
		return ret;
	}

	inline Matrix2D& operator-=(Matrix2D& lhs, const Matrix2D& rhs)
	{
		for (usize row = 0; row < 2; row++)
		{
			lhs[row] -= rhs[row];
		}
		return lhs;
	}

	inline Matrix2D operator*(const Matrix2D& lhs, const f32& rhs)
	{
		Matrix2D ret;
		for (usize row = 0; row < 2; row++)
		{
			ret[row] = lhs[row] * rhs;
		}

		return ret;
	}

	inline Matrix2D operator*(const Matrix2D& lhs, const Matrix2D& rhs)
	{
		Matrix2D result;

		result[0][0] = rhs[0][0] * lhs[0][0] + rhs[0][1] * lhs[1][0];
		result[0][1] = rhs[0][0] * lhs[0][1] + rhs[0][1] * lhs[1][1];

		result[1][0] = rhs[1][0] * lhs[0][0] + rhs[1][1] * lhs[1][0];
		result[1][1] = rhs[1][0] * lhs[0][1] + rhs[1][1] * lhs[1][1];

		return result;
	}


	inline Vector2D const operator*(const Matrix2D& lhs, const Vector2D& rhs)
	{
		return lhs[0] * rhs.x + lhs[1] * rhs.y;
	}

	inline Matrix2D operator/(const Matrix2D& lhs, const f32& rhs)
	{
		Matrix2D ret;
		for (usize row = 0; row < 2; row++)
		{
			ret[row] = lhs[row] / rhs;
		}

		return ret;
	}

	inline Matrix2D& operator/=(Matrix2D& lhs, const f32& rhs)
	{
		Matrix2D ret;
		for (usize row = 0; row < 2; row++)
		{
			lhs[row] /= rhs;
		}

		return ret;
	}

	inline bool operator==(const Matrix2D& lhs, const Matrix2D& rhs)
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


	inline bool operator!=(const Matrix2D& lhs, const Matrix2D& rhs)
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


	inline Matrix2D transpose(const Matrix2D& source)
	{
		Matrix2D result;
		for (usize i = 0; i < 2; i++)
		{
			for (usize j = 0; j < 2; j++)
				result[i][j] = source[j][i];
		}
	}

	inline f32 determinant(const Matrix2D& source)
	{
		return source[0][0] * source[1][1] - source[1][0] * source[0][1];
	}

	inline Matrix2D inverse(const Matrix2D& source)
	{
		Matrix2D result;
		result[0][0] = source[1][1];
		result[1][1] = source[0][0];

		result[1][0] = -source[1][0];
		result[0][1] = -source[0][1];

		result /= determinant(source);
		return result;
	}
	
}
