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
	EulerAngles eu(degToRad(30), degToRad(45), degToRad(60));
	Quaternion result = eulerAnglesToQuaternion(eu);
	Quaternion result1 = Quaternion(0.5319f, 0.3919f, 0.2005f, 0.72331f);
	EXPECT_TRUE(TestUtils::almostEqual(result, result1));


	EulerAngles eu2(degToRad(0), degToRad(90), degToRad(180));
	Quaternion result2 = eulerAnglesToQuaternion(eu2);
	Quaternion result3 = Quaternion(0.707106f, 0.707106f, 0.0f, 0.0f);
	EXPECT_TRUE(TestUtils::almostEqual(result2, result3));

}

TEST(Quaternion, quaternionToEulerAngles)
{
	Quaternion test1(1, 1, 0, 1);
	EulerAngles result1 =  quaternionToEulerAngles(test1);
	EulerAngles hardResult1(MATH_PI_2, MATH_PI_2, 0);
	EXPECT_TRUE(TestUtils::almostEqual(result1, hardResult1));

	Quaternion test2(0.53, 0.39, 0.72 ,0.72);
	EulerAngles result2 = quaternionToEulerAngles(test2);
	EulerAngles hardResult2(degToRad(72.71439), degToRad(90), 0);
	EXPECT_TRUE(TestUtils::almostEqual(result2, hardResult2));
	
}

TEST(Quaternion, matrix4ToQuaternion)
{
	Matrix4 test1;
	Quaternion result1 = matrix4ToQuaternion(test1);
	Quaternion hardResult1(0,0,0,1);
	EXPECT_TRUE(TestUtils::almostEqual(result1, hardResult1));

	Matrix4 test2{ {0.1f,0.2f,0.3f,0},{ 0.4f,0.5f,0.6f,0},{ 0.7f,0.8f,0.9f,0},{0,0,0,1}};
	Quaternion result2 = matrix4ToQuaternion(test2);
	Quaternion hardResult2(-0.063245f, 0.1264911f, -0.063245f, 0.7905694);
	EXPECT_TRUE(TestUtils::almostEqual(result2, hardResult2));

	Matrix4 test3(Matrix3({ 1.0f,0.2f,0.3f},{ 0.4f,0.5f,0.6f},{ 0.7f,0.8f,-3.0f}));
	Quaternion result3 = matrix4ToQuaternion(test3);
	Quaternion hardResult3(1.060660f, 0.141421f, 0.23570f, -0.04714f);
	EXPECT_TRUE(TestUtils::almostEqual(result3, hardResult3));


	Matrix4 test4(Matrix3({ -15.0f,0.2f,0.3f }, { 0.4f,0.5f,0.6f }, { 0.7f,0.8f,-3.0f }));
	Quaternion result4 = matrix4ToQuaternion(test4);
	Quaternion hardResult4(0.0679366f, 2.2079f, 0.15851f, 0.045291f);
	EXPECT_TRUE(TestUtils::almostEqual(result4, hardResult4));

	Matrix4 test5(Matrix3({ -3.0f,0.2f,0.3f }, { 0.4f,-2.0f,0.6f }, { 0.7f,0.8f,-1.0f }));
	Quaternion result5 = matrix4ToQuaternion(test5);
	Quaternion hardResult5(0.2236067f, 0.3130495f, 1.11803f, -0.04472f);
	EXPECT_TRUE(TestUtils::almostEqual(result5, hardResult5));

}

TEST(Quaternion, quaternionToMatrix4)
{
	Quaternion test1(0.859f,0.803f,0.27, 0.538f);
	Matrix4 result1 =quaternionToMatrix4(test1);
	Matrix4 hardResult1(Matrix3
		(
		{ -0.435417891f,1.67007f,-0.40016f},
		{ 1.08903f,-0.621562123f,1.3579f },
		{ 1.32788f,-0.49066f,-1.76537991f }
		));

	EXPECT_TRUE(TestUtils::almostEqual(result1, hardResult1));

}

TEST(Quaternion, slerp)
{

}
