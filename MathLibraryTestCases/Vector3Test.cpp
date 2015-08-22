#pragma once
#include <gtest\gtest.h>
#include <Vector3D.h>
#include "TestUtils.h"
using namespace math;

TEST(Vector3D, Constructor)
{
	Vector3D vec1(1, 2,3);

	f32 arrayInit[3] = { 1.0f, 2.0f , 3.0f };
	Vector3D vec2{ arrayInit };

	Vector3D vec3{ 1.0f,2.0f,3.0f };

	EXPECT_TRUE(vec1.x == vec2.x &&  vec2.x == vec3.x 
		     && vec1.y == vec2.y && vec2.y == vec3.y 
			 && vec1.z == vec2.z && vec2.z == vec3.z);
}

TEST(Vector3D, AssignmentPlusEqual)
{
	Vector3D vec1(1, 2,3);
	Vector3D vec2(3,2, 1);

	vec2 += vec1;

	EXPECT_TRUE(vec2.x == 4 && vec2.y == 4 && vec2.z == 4);

}

TEST(Vector3D, AssignmentPlusEqualScalar)
{
	Vector3D vec1(1, 2,3);
	f32 scaler = 2.0f;

	vec1 += scaler;

	EXPECT_TRUE(vec1.x == 3 && vec1.y == 4 && vec1.z == 5);

}

TEST(Vector3D, AssignmentMinusEqualVector)
{
	Vector3D vec1(1, 2,3);
	Vector3D vec2(2, 1, 3);

	vec2 -= vec1;
	EXPECT_TRUE(vec2.x == 1 && vec2.y == -1 && vec2.z == 0);

}

TEST(Vector3D, AssignmentMinusEqualScalar)
{
	Vector3D vec1(3, 4,5);
	f32 scaler = 2.0f;

	vec1 -= scaler;

	EXPECT_TRUE(vec1.x == 1 && vec1.y == 2 && vec1.z == 3);

}

TEST(Vector3D, AssignmentMultiplyEqualVector)
{
	Vector3D vec1(2, 2 , 2);
	Vector3D vec2(2, 3 , 4);

	vec2 *= vec1;
	EXPECT_TRUE(vec2.x == 4 && vec2.y == 6 && vec2.z == 8);

}

TEST(Vector3D, AssignmentMultiplyEqualScalar)
{
	Vector3D vec1(3, 4 ,5);
	f32 scaler = 2.0f;

	vec1 *= scaler;

	EXPECT_TRUE(vec1.x == 6 && vec1.y == 8 && vec1.z == 10);

}

TEST(Vector3D, AssignmentDivideEqualVector)
{
	Vector3D vec1(8, 12 , 16);
	Vector3D vec2(2, 3 , 4);

	vec1 /= vec2;
	EXPECT_TRUE(vec1.x == 4 && vec1.y == 4 && vec1.z == 4);

}

TEST(Vector3D, AssignmentDivideEqualScalar)
{
	Vector3D vec1(4, 6 , 8);
	f32 scaler = 2.0f;

	vec1 /= scaler;

	EXPECT_TRUE(vec1.x == 2 && vec1.y == 3 && vec1.z == 4);

}

TEST(Vector3D, CopyConstructor)
{
	Vector3D vec1(4, 6 , 7);
	Vector3D vec2(vec1);

	EXPECT_TRUE(vec2.x == vec1.x && vec2.y == vec1.y && vec2.z == vec1.z);
}

TEST(Vector3D, AssignmentOperator)
{
	Vector3D vec1(1, 2 ,3);
	Vector3D result = vec1;

	EXPECT_TRUE(vec1.x == result.x && vec1.y == result.y && vec1.z == result.z);

}


TEST(Vector3D, ArraySubscript)
{
	Vector3D vec1(1, 2 ,5);

	f32 x = vec1[0];
	f32 y = vec1[1];
	f32 z = vec1[2];

	EXPECT_TRUE(x == 1 && y == 2 && z == 5);

}


TEST(Vector3D, Length)
{
	Vector3D vec1(1, 2 , 3);

	EXPECT_TRUE(vec1.length() == sqrt(14.00f));
}


//---------------------------------------Class methods finished here----------------------------


TEST(Vector3D, Add)
{
	Vector3D vec1(2, 5 , 7);
	Vector3D vec2(3, 6 , 9);

	Vector3D result = vec1 + vec2;

	EXPECT_TRUE(result.x == 5 && result.y == 11 && result.z == 16);
}

TEST(Vector3D, Subtract)
{
	Vector3D vec1(2, 10 , 9);
	Vector3D vec2(3, 6, 11);

	Vector3D result = vec1 - vec2;

	EXPECT_TRUE(result.x == -1 && result.y == 4 && result.z == -2);
}

TEST(Vector3D, Negate)
{
	Vector3D vec1(2, 10, 9);
	
	Vector3D result = -vec1;

	EXPECT_TRUE(result.x == -2 && result.y == -10 && result.z == -9);
}


TEST(Vector3D, Multiply)
{
	Vector3D vec1(2, 5,7);
	Vector3D vec2(3, 2 ,1);

	Vector3D result = vec1 * vec2;

	EXPECT_TRUE(result.x == 6 && result.y == 10 && result.z == 7);
}


TEST(Vector3D, MultiplyScalar)
{
	Vector3D vec1(2, 5 , 10);
	f32 scaler = 2.0f;

	Vector3D result = vec1 * scaler;

	EXPECT_TRUE(result.x == 4 && result.y == 10 && result.z == 20);
}


TEST(Vector3D, Divide)
{
	Vector3D vec1(21, 15 , 10);
	Vector3D vec2(3, 5 , 2);

	Vector3D result = vec1 / vec2;

	EXPECT_TRUE(result.x == 7 && result.y == 3 && result.z == 5);
}


TEST(Vector3D, DivideScalar)
{
	Vector3D vec1(2, 10 , 16);
	f32 scaler = 2.0f;

	Vector3D result = vec1 / scaler;

	EXPECT_TRUE(result.x ==  1 && result.y == 5 && result.z == 8);
}

TEST(Vector3D, IsEqual)
{
	Vector3D vec1(1, 2 , 4);
	Vector3D vec2(1, 2 , 4);

	EXPECT_TRUE(vec1 == vec2);
}

TEST(Vector3D, IsNotEqual)
{
	Vector3D vec1(1, 2 ,1);
	Vector3D vec2(1, 3 ,1);

	EXPECT_TRUE(vec1 != vec2);
}


TEST(Vector3D, Dot)
{
	Vector3D vec1(1, 2 , 3);
	Vector3D vec2(2, 1 , -5);

	f32 result = dot(vec1, vec2);
	f32 result1 = 1 * 2 + 2 * 1 + 3 * -5;

	EXPECT_TRUE(result == result1);
}

TEST(Vector3D, Cross)
{
	Vector3D vec1(1, -7 , 1);
	Vector3D vec2(5 , 2 , 4);

	Vector3D result = cross(vec1, vec2);
	Vector3D reverseCross = cross(vec2, vec1);

	EXPECT_TRUE(result == Vector3D(-30, 1 , 37 ));
	EXPECT_TRUE(result == -reverseCross);

	EXPECT_TRUE(dot(result,vec1) == 0);
	EXPECT_TRUE(dot(reverseCross, vec1) == 0);

	EXPECT_TRUE(dot(result, vec2) == 0);
	EXPECT_TRUE(dot(reverseCross, vec2) == 0);

}



TEST(Vector3D, Distance)
{
	Vector3D from(-7, -4 ,3);
	Vector3D to(17, 6 , 2.5);

	f32 dist = distance(from, to);

	EXPECT_TRUE(TestUtils::almostEqual(dist, 26.004807f));
}




