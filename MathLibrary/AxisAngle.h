#pragma once
#include <Types.h>
#include <Vector3.h>

namespace math
{
	struct AxisAngle
	{
		AxisAngle() :axis(0, 0, 1), angle(0)
		{
		}
		AxisAngle(Vector3 axis, f32 angle) :axis(axis), angle(angle)
		{
		}
		Vector3 axis;
		f32 angle;
		

	};
}
