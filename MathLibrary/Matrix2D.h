#pragma once
#include <MathDefine.h>
#include <Vector2D.h>
#include <math.h>

namespace math
{
	struct Matrix2D
	{

		efloat a, b,
			  c, d;

		explicit Matrix2D(efloat a = 1.0f, efloat b = 0.0f, efloat c = 0.0f, efloat d = 1.0f) :a(a), b(b), c(c), d(d)
		{
		}

		inline static Matrix2D createRotateMatrix(efloat angle)
		{
			efloat cosTheta = cos(angle);
			efloat sinTheta = sin(angle);

			return Matrix2D
				(
					cosTheta,-sinTheta,
					sinTheta,cosTheta

				);
		}

	};



	inline Vector2D operator*(const Matrix2D& lhs, const Vector2D& rhs)
	{

		return Vector2D
			(
				lhs.a*rhs.x + lhs.b*rhs.y ,  
				lhs.c*rhs.x + lhs.d*rhs.y 
			);
	}
}
