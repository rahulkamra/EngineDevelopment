#pragma once
#include <gtest\gtest.h>
#include <Quaternion.h>

using namespace math;
TEST(Quaternion, Constructor)
{

}


TEST(Quaternion, ArraySubScript)
{

}

TEST(Quaternion, AssignmentOperator)
{

}

TEST(Quaternion, PlusOperator)
{

}

TEST(Quaternion, PlusEqualOperator)
{

}

TEST(Quaternion, MinusOperator)
{

}

TEST(Quaternion, NegativeOperator)
{

}

TEST(Quaternion, MinusEqualOperator)
{

}

TEST(Quaternion, QuaternionProductWithQuaternion)
{
	Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
	Quaternion q2(1.0f, 2.0f, 3.0f, 4.0f);
	Quaternion q3 = q1 * q2;

	Quaternion result = Quaternion(8,16,24,2);

	EXPECT_TRUE(q3 == result);
}

TEST(Quaternion, QuaternionProductWithVector)
{
	Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);
	Vector3 v = {1,0,0};
	Vector3 v1 = q * v;
	Vector3  result = Vector3{ -25 , 28 , -10 };
	EXPECT_TRUE(v1 == result);
}

TEST(Quaternion, QuaternionProductWithScaler)
{

}

TEST(Quaternion, QuaternionDivisionWithQuaternion)
{

}

TEST(Quaternion, QuaternionDivisionEqualWithQuaternion)
{

}
TEST(Quaternion, QuaternionDivisionWithScaler)
{

}

TEST(Quaternion, IsEqual)
{

}

TEST(Quaternion, IsNotEqual)
{

}

TEST(Quaternion, LengthSquare)
{

}

TEST(Quaternion, Length)
{

}


TEST(Quaternion, Dot)
{

}


TEST(Quaternion, Cross)
{

}


TEST(Quaternion, Conjugate)
{

}

TEST(Quaternion, normalize)
{

}

TEST(Quaternion, axisAngleToQuaternion)
{

}

TEST(Quaternion, eulerAnglesToQuaternion)
{

}

TEST(Quaternion, matrix4ToQuaternion)
{

}
TEST(Quaternion, quaternionToAxis)
{

}

TEST(Quaternion, quaternionToAngle)
{

}

TEST(Quaternion, slerp)
{

}
