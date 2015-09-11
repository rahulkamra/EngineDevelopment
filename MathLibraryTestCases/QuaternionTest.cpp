#pragma once
#include <gtest\gtest.h>
#include <Quaternion.h>
#include "TestUtils.h"
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


TEST(Quaternion, Inverse)
{
	Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);
	q.normalize();

	Quaternion q1 = inverse(q);
	Vector3 v = Vector3{ 1, -2 , -3 };


	Vector3  qv = q * v;
	Vector3  qvv = (q1 * qv);
	
	EXPECT_TRUE(TestUtils::almostEqual(qvv,v));


}


TEST(Quaternion, Conjugate)
{

}

TEST(Quaternion, normalize)
{
	Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
	Quaternion q2(1.0f, 2.0f, 3.0f, 4.0f);
	q1.normalize();
	Quaternion q3 = normalize(q2);

	Quaternion q4((f32)1 / sqrt(30), (f32)2 / sqrt(30), (f32)3 / sqrt(30), (f32)4 / sqrt(30));
	EXPECT_TRUE(TestUtils::almostEqual(q1, q3));
	EXPECT_TRUE(TestUtils::almostEqual(q1, q4));
	EXPECT_TRUE(TestUtils::almostEqual(q3, q4));
}

TEST(Quaternion, axisAngleToQuaternion)
{

}

TEST(Quaternion, eulerAnglesToQuaternion)
{
	EulerAngles eu(degToRad(45), degToRad(45), degToRad(45));
	Quaternion result = eulerAnglesToQuaternion(eu);
	Quaternion result1 = Quaternion(0.461939f, 0.461939f, 0.19134f, 0.73253f);
	EXPECT_TRUE(TestUtils::almostEqual(result, result1));
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
