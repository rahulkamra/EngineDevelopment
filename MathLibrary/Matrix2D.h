#pragma once
#include <MathDefine.h>
#include <Vector2D.h>
#include <math.h>
#include <array>
#include <StringUtils.h>

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

			Vector2D data[2];
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
			return Matrix2D();
			//	return Matrix2D
				//	(
					//	cosTheta,-sinTheta,
					//	sinTheta,cosTheta

					//);
		}


		//we need const as well as non cost operators.
		inline const Vector2D& operator[](usize index) const { return data[index]; }
		inline Vector2D& operator[](usize index){return data[index];}

		
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
			//if (colIndex == 0)
			//{
			//	this->a = col.x;
			//	this->c = col.y;
			//}
			//else if (colIndex == 1)
			//{
			//	this->b = col.x;
			//	this->d = col.y;
			///}
			//else
			//{
			//	cout << "Unknow Index";
			//}
		}

		inline const  void  setRow(const int rowIndex, const Vector2D row)
		{
			//if (rowIndex == 0)
			//{
			//	this->a = row.x;
			//	this->b = row.y;
			//}
			//else if (rowIndex == 1)
			//{
			//	this->c = row.x;
			//	this->d = row.y;
			//}
			//else
			//{
			//	cout << "Unknow Index";
			//}

		}


		//inline std::string toString()
		//{
			//return
				//"a: " + StringUtils::toString(this->a) + "\n" + "b: " + StringUtils::toString(this->b) + "\n" +
				//"c: " + StringUtils::toString(this->c) + "\n" + "d: " + StringUtils::toString(this->d) + "\n";
		//}

	};


	//vector will always come on the right side / 2*2 matric and 2*1 vector (vector is a column major one)
	inline Vector2D const operator*(const Matrix2D& lhs, const Vector2D& rhs)
	{
		return lhs[0] * rhs.x + lhs[1] * rhs.y;
	}

}
