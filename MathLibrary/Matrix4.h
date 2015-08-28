#pragma once
#include <MathDefine.h>
#include <Vector4.h>
#include <math.h>
#include <array>

namespace math
{

	/*
	m[0][0] m[1][0] m[2][0] m[3][0]
	m[0][1] m[1][1] m[2][1] m[3][1]
	m[0][2] m[1][2] m[2][2] m[3][2]
	m[0][3] m[1][3] m[2][3] m[3][3]
	//Column major matrix and this is how it can be accessed
	*/
	struct Matrix4
	{

		union
		{
			struct
			{
				Vector4 x, y, z , w;
			};

			Vector4 vectors[4];
		};


		Matrix4(const Matrix4& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			this->w = rhs.w;
		}

		explicit Matrix4() :
			x(1, 0, 0, 0),
			y(0, 1, 0, 0),
			z(0, 0, 1 ,0),
			w(0, 0, 0, 1)
		{
		}

		explicit Matrix4(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4) :
			x(v1),
			y(v2),
			z(v3),
			w(v4)
		{

		}

		//we need const as well as non cost operators.
		inline const Vector4& operator[](usize index) const { return vectors[index]; }
		inline Vector4& operator[](usize index) { return vectors[index]; }

		inline Matrix4& operator=(const Matrix4& rhs)
		{
			for (usize col = 0; col < 4; col++)
			{
				(*this)[col] = rhs[col];
			}

			return *this;
		}


	};


	inline Matrix4 operator+(const Matrix4& lhs, const Matrix4& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			ret[col] = lhs[col] + rhs[col];
		}

		return ret;
	}


	inline Matrix4& operator+=(Matrix4& lhs, const Matrix4& rhs)
	{
		for (usize col = 0; col < 4; col++)
		{
			lhs[col] += rhs[col];
		}
		return lhs;
	}

	inline Matrix4 operator-(const Matrix4& lhs, const Matrix4& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			ret[col] = lhs[col] - rhs[col];
		}
		return ret;
	}

	inline Matrix4& operator-=(Matrix4& lhs, const Matrix4& rhs)
	{
		for (usize col = 0; col < 4; col++)
		{
			lhs[col] -= rhs[col];
		}
		return lhs;
	}

	inline Matrix4 operator*(const Matrix4& lhs, const f32& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			ret[col] = lhs[col] * rhs;
		}

		return ret;
	}

	inline Matrix4 operator*(const Matrix4& lhs, const Matrix4& rhs)
	{
		Matrix4 result;
		//result[0] = lhs[0] * rhs[0][0] + lhs[1] * rhs[0][1] + lhs[2] * rhs[0][2];
		//result[1] = lhs[0] * rhs[1][0] + lhs[1] * rhs[1][1] + lhs[2] * rhs[1][2];
		//result[2] = lhs[0] * rhs[2][0] + lhs[1] * rhs[2][1] + lhs[2] * rhs[2][2];
		return result;
	}


	inline Vector4 const operator*(const Matrix4& lhs, const Vector4& rhs)
	{
		return Vector4();
		//return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
	}

	inline Matrix4 operator/(const Matrix4& lhs, const f32& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			ret[col] = lhs[col] / rhs;
		}

		return ret;
	}

	inline Matrix4& operator/=(Matrix4& lhs, const f32& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			lhs[col] /= rhs;
		}

		return ret;
	}

	inline bool operator==(const Matrix4& lhs, const Matrix4& rhs)
	{
		for (usize col = 0; col < 4; col++)
		{
			if (lhs[col] != rhs[col])
			{
				return false;
			}
		}
		return true;
	}


	inline bool operator!=(const Matrix4& lhs, const Matrix4& rhs)
	{
		for (usize col = 0; col < 4; col++)
		{
			if (lhs[col] != rhs[col])
			{
				return true;
			}
		}
		return false;
	}


	inline Matrix4 transpose(const Matrix4& source)
	{
		Matrix4 result;
		for (usize col = 0; col < 4; col++)
		{
			for (usize row = 0; row < 4; row++)
				result[col][row] = source[row][col];
		}
		return result;
	}

	inline f32 determinant(const Matrix4& source)
	{
		//return source[0][0] * (source[1][1] * source[2][2] - source[2][1] * source[1][2]) -
			//source[1][0] * (source[0][1] * source[2][2] - source[0][2] * source[2][1]) +
			//source[2][0] * (source[0][1] * source[1][2] - source[0][2] * source[1][1]);
	}

	inline Matrix4 inverse(const Matrix4& source)
	{
		Matrix4 cofactorsTransposed;
		//cofactorsTransposed[0][0] = +(source[1][1] * source[2][2] - source[1][2] * source[2][1]);
		//cofactorsTransposed[1][0] = -(source[1][0] * source[2][2] - source[2][0] * source[1][2]);
		//cofactorsTransposed[2][0] = +(source[1][0] * source[2][1] - source[2][0] * source[1][1]);

	//	cofactorsTransposed[0][1] = -(source[0][1] * source[2][2] - source[2][1] * source[0][2]);
		//cofactorsTransposed[1][1] = +(source[0][0] * source[2][2] - source[2][0] * source[0][2]);
		//cofactorsTransposed[2][1] = -(source[0][0] * source[2][1] - source[2][0] * source[0][1]);

		//cofactorsTransposed[0][2] = +(source[0][1] * source[2][2] - source[0][2] * source[1][1]);
		//cofactorsTransposed[1][2] = -(source[0][0] * source[1][2] - source[1][0] * source[0][2]);
		//cofactorsTransposed[2][2] = +(source[0][0] * source[1][1] - source[1][0] * source[0][1]);

		//cofactorsTransposed /= determinant(source);

		return cofactorsTransposed;
	}

	inline std::ostream& operator<<(std::ostream &out, Matrix4& source)
	{
		out << "Matrix4(" << source.x << ", \n " <<
							source.y << ", \n" <<
							source.z << ", \n" <<
							source.w << ")";
		return out;
	}

}
