#pragma once
#include <gtest\gtest.h>
#include <Vector3.h>
#include "TestUtils.h"
using namespace math;

TEST(Vector3, Constructor)
{
	Vector3 vec1(1, 2,3);

	f32 arrayInit[3] = { 1.0f, 2.0f , 3.0f };
	Vector3 vec2{ arrayInit };

	Vector3 vec3{ 1.0f,2.0f,3.0f };

	EXPECT_TRUE(vec1.x == vec2.x &&  vec2.x == vec3.x 
		     && vec1.y == vec2.y && vec2.y == vec3.y 
			 && vec1.z == vec2.z && vec2.z == vec3.z);
}

TEST(Vector3, AssignmentPlusEqual)
{
	Vector3 vec1(1, 2,3);
	Vector3 vec2(3,2, 1);

	vec2 += vec1;

	EXPECT_TRUE(vec2.x == 4 && vec2.y == 4 && vec2.z == 4);

}

TEST(Vector3, AssignmentPlusEqualScalar)
{
	Vector3 vec1(1, 2,3);
	f32 scaler = 2.0f;

	vec1 += scaler;

	EXPECT_TRUE(vec1.x == 3 && vec1.y == 4 && vec1.z == 5);

}

TEST(Vector3, AssignmentMinusEqualVector)
{
	Vector3 vec1(1, 2,3);
	Vector3 vec2(2, 1, 3);

	vec2 -= vec1;
	EXPECT_TRUE(vec2.x == 1 && vec2.y == -1 && vec2.z == 0);

}

TEST(Vector3, AssignmentMinusEqualScalar)
{
	Vector3 vec1(3, 4,5);
	f32 scaler = 2.0f;

	vec1 -= scaler;

	EXPECT_TRUE(vec1.x == 1 && vec1.y == 2 && vec1.z == 3);

}

TEST(Vector3, AssignmentMultiplyEqualVector)
{
	Vector3 vec1(2, 2 , 2);
	Vector3 vec2(2, 3 , 4);

	vec2 *= vec1;
	EXPECT_TRUE(vec2.x == 4 && vec2.y == 6 && vec2.z == 8);

}

TEST(Vector3, AssignmentMultiplyEqualScalar)
{
	Vector3 vec1(3, 4 ,5);
	f32 scaler = 2.0f;

	vec1 *= scaler;

	EXPECT_TRUE(vec1.x == 6 && vec1.y == 8 && vec1.z == 10);

}

TEST(Vector3, AssignmentDivideEqualVector)
{
	Vector3 vec1(8, 12 , 16);
	Vector3 vec2(2, 3 , 4);

	vec1 /= vec2;
	EXPECT_TRUE(vec1.x == 4 && vec1.y == 4 && vec1.z == 4);

}

TEST(Vector3, AssignmentDivideEqualScalar)
{
	Vector3 vec1(4, 6 , 8);
	f32 scaler = 2.0f;

	vec1 /= scaler;

	EXPECT_TRUE(vec1.x == 2 && vec1.y == 3 && vec1.z == 4);

}

TEST(Vector3, CopyConstructor)
{
	Vector3 vec1(4, 6 , 7);
	Vector3 vec2(vec1);

	EXPECT_TRUE(vec2.x == vec1.x && vec2.y == vec1.y && vec2.z == vec1.z);
}

TEST(Vector3, AssignmentOperator)
{
	Vector3 vec1(1, 2 ,3);
	Vector3 result = vec1;

	EXPECT_TRUE(vec1.x == result.x && vec1.y == result.y && vec1.z == result.z);

}


TEST(Vector3, ArraySubscript)
{
	Vector3 vec1(1, 2 ,5);

	f32 x = vec1[0];
	f32 y = vec1[1];
	f32 z = vec1[2];

	EXPECT_TRUE(x == 1 && y == 2 && z == 5);

}


TEST(Vector3, Length)
{
	Vector3 vec1(1, 2 , 3);

	EXPECT_TRUE(vec1.length() == sqrt(14.00f));
}


//---------------------------------------Class methods finished here----------------------------


TEST(Vector3, Add)
{
	Vector3 vec1(2, 5 , 7);
	Vector3 vec2(3, 6 , 9);

	Vector3 result = vec1 + vec2;

	EXPECT_TRUE(result.x == 5 && result.y == 11 && result.z == 16);
}

TEST(Vector3, Subtract)
{
	Vector3 vec1(2, 10 , 9);
	Vector3 vec2(3, 6, 11);

	Vector3 result = vec1 - vec2;

	EXPECT_TRUE(result.x == -1 && result.y == 4 && result.z == -2);
}

TEST(Vector3, Negate)
{
	Vector3 vec1(2, 10, 9);
	
	Vector3 result = -vec1;

	EXPECT_TRUE(result.x == -2 && result.y == -10 && result.z == -9);
}


TEST(Vector3, Multiply)
{
	Vector3 vec1(2, 5,7);
	Vector3 vec2(3, 2 ,1);

	Vector3 result = vec1 * vec2;

	EXPECT_TRUE(result.x == 6 && result.y == 10 && result.z == 7);
}


TEST(Vector3, MultiplyScalar)
{
	Vector3 vec1(2, 5 , 10);
	f32 scaler = 2.0f;

	Vector3 result = vec1 * scaler;

	EXPECT_TRUE(result.x == 4 && result.y == 10 && result.z == 20);
}


TEST(Vector3, Divide)
{
	Vector3 vec1(21, 15 , 10);
	Vector3 vec2(3, 5 , 2);

	Vector3 result = vec1 / vec2;

	EXPECT_TRUE(result.x == 7 && result.y == 3 && result.z == 5);
}


TEST(Vector3, DivideScalar)
{
	Vector3 vec1(2, 10 , 16);
	f32 scaler = 2.0f;

	Vector3 result = vec1 / scaler;

	EXPECT_TRUE(result.x ==  1 && result.y == 5 && result.z == 8);
}

TEST(Vector3, IsEqual)
{
	Vector3 vec1(1, 2 , 4);
	Vector3 vec2(1, 2 , 4);

	EXPECT_TRUE(vec1 == vec2);
}

TEST(Vector3, IsNotEqual)
{
	Vector3 vec1(1, 2 ,1);
	Vector3 vec2(1, 3 ,1);

	EXPECT_TRUE(vec1 != vec2);
}


TEST(Vector3, Dot)
{
	Vector3 vec1(1, 2 , 3);
	Vector3 vec2(2, 1 , -5);

	f32 result = dot(vec1, vec2);
	f32 result1 = 1 * 2 + 2 * 1 + 3 * -5;

	EXPECT_TRUE(result == result1);
}

TEST(Vector3, Cross)
{
	Vector3 vec1(1, -7 , 1);
	Vector3 vec2(5 , 2 , 4);

	Vector3 result = cross(vec1, vec2);
	Vector3 reverseCross = cross(vec2, vec1);

	EXPECT_TRUE(result == Vector3(-30, 1 , 37 ));
	EXPECT_TRUE(result == -reverseCross);

	EXPECT_TRUE(dot(result,vec1) == 0);
	EXPECT_TRUE(dot(reverseCross, vec1) == 0);

	EXPECT_TRUE(dot(result, vec2) == 0);
	EXPECT_TRUE(dot(reverseCross, vec2) == 0);

}



TEST(Vector3, Distance)
{
	Vector3 from(-7, -4 ,3);
	Vector3 to(17, 6 , 2.5);

	f32 dist = distance(from, to);

	EXPECT_TRUE(TestUtils::almostEqual(dist, 26.004807f));
}

//http://www.fundza.com/vectors/normalize/
TEST(Vector3, NormalizeSelf)
{
	Vector3 vec1(3, 1, 2);
	vec1.normalize();

	EXPECT_TRUE(TestUtils::almostEqual(vec1.x, 0.80171f) && TestUtils::almostEqual(vec1.y, 0.26723677f) && TestUtils::almostEqual(vec1.z, 0.5344735f));
}

//http://www.fundza.com/vectors/normalize/
TEST(Vector3, ReturnNormalize)
{
	Vector3 vec1(3, 1, 2);
	Vector3 vec2 = normalize(vec1);

	EXPECT_TRUE(TestUtils::almostEqual(vec2.x, 0.80171f) && TestUtils::almostEqual(vec2.y, 0.26723677f) && TestUtils::almostEqual(vec2.z, 0.5344735f));
}

TEST(Vector3, Reflect)
{
	Vector3 vec1(3, 4, 5);
	Vector3 vec2(0, 1, 0);
	Vector3 vec3 = reflect(vec1, vec2);
	
	EXPECT_TRUE(vec3.x == -3.0f && vec3.y == 4.0f && vec3.z == -5.0f);
}

TEST(Vector3, AngleBetween)
{
	Vector3 vec1(2, 3, 4);
	Vector3 vec2(3, 4, 5);
	f32 result = angle(vec1, vec2);

	EXPECT_TRUE(TestUtils::almostEqual(result, 0.06437119817f));
}

