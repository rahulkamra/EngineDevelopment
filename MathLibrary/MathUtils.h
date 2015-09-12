#pragma once

#include <Types.h>
#include <cmath>
#include <MathDefine.h>
namespace math
{
	inline f32  acos(f32 angle)
	{
		return _CSTD acos(angle);
	}

	inline f32  cos(f32 angle)
	{
		return _CSTD cos(angle);
	}

	inline f32  sin(f32 angle)
	{
		return _CSTD sin(angle);
	}
	inline f32  tan(f32 angle)
	{
		return _CSTD tan(angle);
	}


	inline f32  asin(f32 scalar)
	{
		return _CSTD asin(scalar);
	}

	inline f32  degToRad(f32 deg)
	{
		return deg * MATH_DEG_RAD;

	}

	inline f32  radToDeg(f32 rad)
	{
		return rad * MATH_RAD_DEG;
	}

	inline f32  atan2(f32 x , f32 y)
	{
		return _CSTD atan2(x,y);
	}

	inline f32  sqrt(f32 value)
	{
		return _CSTD sqrt(value);
	}
}


