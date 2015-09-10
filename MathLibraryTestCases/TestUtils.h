#pragma once;
#include <math.h>
#include <Matrix2.h>
#include <Matrix3.h>
#include <Matrix4.h>
#define TEST_UTILS_PRECISION 0.0001

using namespace math;
class TestUtils
{

public :
	bool static almostEqual(f32 lhs , f32 rhs)
	{
		
		if (abs(lhs - rhs) < TEST_UTILS_PRECISION )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	
	bool static almostEqual(f32 lhs, f64 rhs)
	{			
		if (abs(lhs - rhs) < TEST_UTILS_PRECISION)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool static almostEqual(Matrix2& lhs, Matrix2& rhs)
	{
		return almostEqual(lhs.x, rhs.x) && almostEqual(lhs.y, rhs.y);
	}


	bool static almostEqual(Matrix3& lhs, Matrix3& rhs)
	{
		return almostEqual(lhs.x, rhs.x) && almostEqual(lhs.y, rhs.y) && almostEqual(lhs.z, rhs.z);
	}

	bool static almostEqual(const Vector2& lhs, const Vector2& rhs)
	{
		return almostEqual(lhs.x, rhs.x) && almostEqual(lhs.y, rhs.y);
	}

	bool static almostEqual(const Vector3& lhs, const Vector3& rhs)
	{
		return almostEqual(lhs.x, rhs.x) && almostEqual(lhs.y, rhs.y) && almostEqual(lhs.z, rhs.z);
	}

	bool static almostEqual(const Vector4& lhs, const Vector4& rhs)
	{
		return almostEqual(lhs.x, rhs.x) && almostEqual(lhs.y, rhs.y) && almostEqual(lhs.z, rhs.z) && almostEqual(lhs.w, rhs.w);
	}

	bool static almostEqual(const Matrix4& lhs, const Matrix4& rhs)
	{
		return almostEqual(lhs.x, rhs.x) && almostEqual(lhs.y, rhs.y) && almostEqual(lhs.z, rhs.z) && almostEqual(lhs.w, rhs.w);
	}

};

