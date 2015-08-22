#pragma once
#include <gtest\gtest.h>
#include <Vector3D.h>

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

TEST(Vector3D, Add)
{
	Vector3D vec1(2, 5, 6);
	Vector3D vec2(3, 6, 1);

	Vector3D result(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
	Vector3D result1 = vec1 + vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y && result.z == result1.z);
}


TEST(Vector3D, Subtract)
{
	Vector3D vec1(2, 5, 7);
	Vector3D vec2(3, 6, 4);

	Vector3D result(vec1.x - vec2.x, vec1.y - vec2.y,vec1.z - vec2.z);
	Vector3D result1 = vec1 - vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y && result.z == result1.z);
}



TEST(Vector3D, Multiply)
{
	Vector3D vec1(2, 5 , 9);
	float scaler = 2.0f;

	Vector3D result(vec1.x * scaler, vec1.y * scaler, vec1.z * scaler);
	Vector3D result1 = vec1 * scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y && result.z == result1.z);
}


TEST(Vector3D, Divide)
{
	Vector3D vec1(2, 5 , 7);
	float scaler = 2.0f;

	Vector3D result(vec1.x / scaler, vec1.y / scaler, vec1.z / scaler);
	Vector3D result1 = vec1 / scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y && result.z == result1.z);
}


TEST(Vector3D, Dot)
{
	Vector3D vec1(1, 2, 5);
	Vector3D vec2(2, 1, 7);
	float result = dot(vec1,vec2);
	float result1 = 1 * 2 + 2 * 1 + 5 * 7;

	EXPECT_TRUE(result == result1);
}


TEST(Vector3D, AssignmentOperator)
{
	Vector3D vec1(1, 2, 5);
	Vector3D result = vec1;

	EXPECT_TRUE(vec1.x == result.x && vec1.y == result.y && vec1.z == result.z);

}

TEST(Vector3D, AssignmentPlusEqual)
{
	Vector3D vec1(1, 2, 7);
	Vector3D vec2(2, 1, -4);

	vec2 += vec1;

	EXPECT_TRUE(vec2.x == 3 && vec2.y == 3 && vec2.z == 3);

}


TEST(Vector3D, AssignmentMinusEqual)
{
	Vector3D vec1(1, 2, 7);
	Vector3D vec2(2, 1, -5);

	vec2 -= vec1;
	EXPECT_TRUE(vec2.x == 1 && vec2.y == -1 && vec2.z == -12);
}






