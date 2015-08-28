#pragma once
#include <gtest\gtest.h>
#include <Vector4.h>
#include "TestUtils.h"
using namespace math;

TEST(Vector4, Constructor)
{
	Vector4 vec1(1, 2, 3, 4);

	f32 arrayInit[4] = { 1.0f, 2.0f , 3.0f , 4.0f};
	Vector4 vec2{ arrayInit };

	Vector4 vec3{ 1.0f,2.0f,3.0f,4.0f };

	EXPECT_TRUE(vec1.x == vec2.x &&  vec2.x == vec3.x
		&& vec1.y == vec2.y && vec2.y == vec3.y
		&& vec1.z == vec2.z && vec2.z == vec3.z
		&& vec1.w == vec2.w && vec2.w == vec3.w);
}

TEST(Vector4, AssignmentPlusEqual)
{
	Vector4 vec1(1, 2, 3, 4);
	Vector4 vec2(4, 3, 2, 1);

	vec2 += vec1;

	EXPECT_TRUE(vec2.x == 5 && vec2.y == 5 && vec2.z == 5 && vec2.w == 5);

}

TEST(Vector4, AssignmentPlusEqualScalar)
{
	Vector4 vec1(1, 2, 3, 4);
	f32 scaler = 2.0f;

	vec1 += scaler;

	EXPECT_TRUE(vec1.x == 3 && vec1.y == 4 && vec1.z == 5 && vec1.w == 6);

}

TEST(Vector4, AssignmentMinusEqualVector)
{
	Vector4 vec1(1, 2, 3, 4);
	Vector4 vec2(2, 1, 3, 6);

	vec2 -= vec1;
	EXPECT_TRUE(vec2.x == 1 && vec2.y == -1 && vec2.z == 0 && vec2.w == 2);

}

TEST(Vector4, AssignmentMinusEqualScalar)
{
	Vector4 vec1(3, 4, 5, 6);
	f32 scaler = 2.0f;

	vec1 -= scaler;

	EXPECT_TRUE(vec1.x == 1 && vec1.y == 2 && vec1.z == 3 && vec1.w == 4);

}

TEST(Vector4, AssignmentMultiplyEqualVector)
{
	Vector4 vec1(2, 2, 2, 2);
	Vector4 vec2(2, 3, 4, 5);

	vec2 *= vec1;
	EXPECT_TRUE(vec2.x == 4 && vec2.y == 6 && vec2.z == 8 && vec2.w == 10);

}

TEST(Vector4, AssignmentMultiplyEqualScalar)
{
	Vector4 vec1(3, 4, 5, 6);
	f32 scaler = 2.0f;

	vec1 *= scaler;

	EXPECT_TRUE(vec1.x == 6 && vec1.y == 8 && vec1.z == 10 && vec1.w == 12);

}

TEST(Vector4, AssignmentDivideEqualVector)
{
	Vector4 vec1(8, 12, 16, 20);
	Vector4 vec2(2, 3, 4, 5);

	vec1 /= vec2;
	EXPECT_TRUE(vec1.x == 4 && vec1.y == 4 && vec1.z == 4 && vec1.w == 4);

}

TEST(Vector4, AssignmentDivideEqualScalar)
{
	Vector4 vec1(4, 6, 8, 10);
	f32 scaler = 2.0f;

	vec1 /= scaler;

	EXPECT_TRUE(vec1.x == 2 && vec1.y == 3 && vec1.z == 4 && vec1.w == 5);

}

TEST(Vector4, CopyConstructor)
{
	Vector4 vec1(4, 6, 7, 9);
	Vector4 vec2(vec1);

	EXPECT_TRUE(vec2.x == vec1.x && vec2.y == vec1.y && vec2.z == vec1.z && vec2.w == vec1.w);
}

TEST(Vector4, AssignmentOperator)
{
	Vector4 vec1(1, 2, 3, 4);
	Vector4 result = vec1;

	EXPECT_TRUE(vec1.x == result.x && vec1.y == result.y && vec1.z == result.z && vec1.w == result.w);

}


TEST(Vector4, ArraySubscript)
{
	Vector4 vec1(1, 2, 5, 8);

	f32 x = vec1[0];
	f32 y = vec1[1];
	f32 z = vec1[2];
	f32 w = vec1[3];

	EXPECT_TRUE(x == 1 && y == 2 && z == 5 && w == 8);

}


TEST(Vector4, Length)
{
	Vector4 vec1(1, 2, 3, 4);

	EXPECT_TRUE(vec1.length() == sqrt(30.00f));
}


//---------------------------------------Class methods finished here----------------------------


TEST(Vector4, Add)
{
	Vector4 vec1(2, 5, 7, 14);
	Vector4 vec2(3, 6, 9, 15);

	Vector4 result = vec1 + vec2;

	EXPECT_TRUE(result.x == 5 && result.y == 11 && result.z == 16 && result.w == 29);
}

TEST(Vector4, Subtract)
{
	Vector4 vec1(2, 10, 9, 15);
	Vector4 vec2(3, 6, 11, 9);

	Vector4 result = vec1 - vec2;

	EXPECT_TRUE(result.x == -1 && result.y == 4 && result.z == -2 && result.w == 6);
}

TEST(Vector4, Negate)
{
	Vector4 vec1(2, 10, 9, 6);

	Vector4 result = -vec1;

	EXPECT_TRUE(result.x == -2 && result.y == -10 && result.z == -9 && result.w == -6);
}


TEST(Vector4, Multiply)
{
	Vector4 vec1(2, 5, 7, 12);
	Vector4 vec2(3, 2, 1, 5);

	Vector4 result = vec1 * vec2;

	EXPECT_TRUE(result.x == 6 && result.y == 10 && result.z == 7 && result.w == 60);
}


TEST(Vector4, MultiplyScalar)
{
	Vector4 vec1(2, 5, 10, 20);
	f32 scaler = 2.0f;

	Vector4 result = vec1 * scaler;

	EXPECT_TRUE(result.x == 4 && result.y == 10 && result.z == 20 && result.w == 40);
}


TEST(Vector4, Divide)
{
	Vector4 vec1(21, 15, 10, 14);
	Vector4 vec2(3, 5, 2, 7);

	Vector4 result = vec1 / vec2;

	EXPECT_TRUE(result.x == 7 && result.y == 3 && result.z == 5 && result.w == 2);
}


TEST(Vector4, DivideScalar)
{
	Vector4 vec1(2, 10, 16, 18);
	f32 scaler = 2.0f;

	Vector4 result = vec1 / scaler;

	EXPECT_TRUE(result.x == 1 && result.y == 5 && result.z == 8 && result.w == 9);
}

TEST(Vector4, IsEqual)
{
	Vector4 vec1(1, 2, 4, 5);
	Vector4 vec2(1, 2, 4, 5);

	EXPECT_TRUE(vec1 == vec2);
}

TEST(Vector4, IsNotEqual)
{
	Vector4 vec1(1, 2, 1, 6);
	Vector4 vec2(1, 3, 1, 9);

	EXPECT_TRUE(vec1 != vec2);
}


TEST(Vector4, Dot)
{
	Vector4 vec1(1, 2, 3, 4);
	Vector4 vec2(2, 1, -5, 3);

	f32 result = dot(vec1, vec2);
	f32 result1 = 1 * 2 + 2 * 1 + 3 * -5 + 4 * 3;

	EXPECT_TRUE(result == result1);
}


TEST(Vector4, Distance)
{
	Vector4 from(-7, -4, 3, 5);
	Vector4 to(17, 6, 2.5, 5);

	f32 dist = distance(from, to);

	EXPECT_TRUE(TestUtils::almostEqual(dist, 26.004807f));
}

//http://www.fundza.com/vectors/normalize/
TEST(Vector4, NormalizeSelf)
{
	Vector4 vec1(3, 1, 2, 5);
	vec1.normalize();

	EXPECT_TRUE(TestUtils::almostEqual(vec1.x, 0.48038f) && TestUtils::almostEqual(vec1.y, 0.160128f) && TestUtils::almostEqual(vec1.z, 0.320256f) && TestUtils::almostEqual(vec1.w, 0.800640f));
}

//http://www.fundza.com/vectors/normalize/
TEST(Vector4, ReturnNormalize)
{
	Vector4 vec1(3, 1, 2, 5);
	Vector4 vec2 = normalize(vec1);
	std::cout << vec2;
	EXPECT_TRUE(TestUtils::almostEqual(vec2.x, 0.48038f) && TestUtils::almostEqual(vec2.y, 0.160128f) && TestUtils::almostEqual(vec2.z, 0.320256f) && TestUtils::almostEqual(vec2.w, 0.800640f));
}


