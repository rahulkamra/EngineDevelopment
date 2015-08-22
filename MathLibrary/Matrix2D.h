#pragma once
#include <MathDefine.h>
#include <Vector2D.h>
#include <math.h>
#include <StringUtils.h>

namespace math
{
	struct Matrix2D
	{

		f32 a, b,
			  c, d;

		explicit Matrix2D(f32 a = 1.0f, f32 b = 0.0f, f32 c = 0.0f, f32 d = 1.0f) :a(a), b(b), c(c), d(d)
		{
		}

		inline static Matrix2D createRotateMatrix(const f32 angle)
		{
			f32 cosTheta = cos(angle);
			f32 sinTheta = sin(angle);

			return Matrix2D
				(
					cosTheta,-sinTheta,
					sinTheta,cosTheta

				);
		}


		//need to write unit test cases
		inline static Matrix2D createIdentityMatrix()
		{
			return Matrix2D
				(
					1, 0,
					0, 1
				);
		}


		inline Matrix2D inverse()
		{

		}

		inline Matrix2D transpose()
		{

		}


		inline const Vector2D getColumn(const int colIndex)
		{

		}

		inline const Vector2D getRow(const int rowIndex)
		{

		}

		inline const void setColumn(const int colIndex, const Vector2D col)
		{
			if (colIndex == 0)
			{
				this->a = col.x;
				this->c = col.y;
			}
			else if (colIndex == 1)
			{
				this->b = col.x;
				this->d = col.y;
			}
			else
			{
				cout << "Unknow Index";
			}
		}

		inline const  void  setRow(const int rowIndex, const Vector2D row)
		{
			if (rowIndex == 0)
			{
				this->a = row.x;
				this->b = row.y;
			}
			else if (rowIndex == 1)
			{
				this->c = row.x;
				this->d = row.y;
			}
			else
			{
				cout << "Unknow Index";
			}

		}


		inline std::string toString()
		{
			return
				"a: " + StringUtils::toString(this->a) + "\n" + "b: " + StringUtils::toString(this->b) + "\n" +
				"c: " + StringUtils::toString(this->c) + "\n" + "d: " + StringUtils::toString(this->d) + "\n";
		}

	};


	inline Vector2D const operator*(const Matrix2D& lhs, const Vector2D& rhs)
	{

		return Vector2D
			(
				lhs.a*rhs.x + lhs.b*rhs.y ,  
				lhs.c*rhs.x + lhs.d*rhs.y 
			);
	}

	

	
}
