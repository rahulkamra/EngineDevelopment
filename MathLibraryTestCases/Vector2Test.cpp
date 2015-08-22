#pragma once
#include <gtest\gtest.h>
#include <Vector2D.h>
#include "TestUtils.h"

using namespace math;

TEST(Vector2D, Constructor)
{
	Vector2D vec1(1, 2);

	f32 arrayInit[2] = { 1.0f, 2.0f };
	Vector2D vec2{arrayInit};

	Vector2D vec3{1.0f,2.0f};

	EXPECT_TRUE(vec1.x == vec2.x &&  vec2.x  == vec3.x && vec1.y == vec2.y && vec2.y == vec3.y);
}


TEST(Vector2D, AssignmentPlusEqual)
{
	Vector2D vec1(1, 2);
	Vector2D vec2(2, 1);

	vec2 += vec1;

	EXPECT_TRUE(vec2.x == 3 && vec2.y == 3);

}

TEST(Vector2D, AssignmentPlusEqualScalar)
{
	Vector2D vec1(1, 2);
	float scaler = 2.0f;

	vec1 += scaler;

	EXPECT_TRUE(vec1.x == 3 && vec1.y == 4);

}

TEST(Vector2D, AssignmentMinusEqualVector)
{
	Vector2D vec1(1, 2);
	Vector2D vec2(2, 1);

	vec2 -= vec1;
	EXPECT_TRUE(vec2.x == 1 && vec2.y == -1);

}

TEST(Vector2D, AssignmentMinusEqualScalar)
{
	Vector2D vec1(3, 4);
	float scaler = 2.0f;

	vec1 -= scaler;

	EXPECT_TRUE(vec1.x == 1 && vec1.y == 2);

}

TEST(Vector2D, AssignmentMultiplyEqualVector)
{
	Vector2D vec1(2, 2);
	Vector2D vec2(2, 3);

	vec2 *= vec1;
	EXPECT_TRUE(vec2.x == 4 && vec2.y == 6);

}

TEST(Vector2D, AssignmentMultiplyEqualScalar)
{
	Vector2D vec1(3, 4);
	float scaler = 2.0f;

	vec1 *= scaler;

	EXPECT_TRUE(vec1.x == 6 && vec1.y == 8);

}

TEST(Vector2D, AssignmentDivideEqualVector)
{
	Vector2D vec1(8, 12);
	Vector2D vec2(2, 3);

	vec1 /= vec2;
	EXPECT_TRUE(vec1.x == 4 && vec1.y == 4);

}

TEST(Vector2D, AssignmentDivideEqualScalar)
{
	Vector2D vec1(4, 6);
	float scaler = 2.0f;

	vec1 /= scaler;

	EXPECT_TRUE(vec1.x == 2 && vec1.y == 3);

}

TEST(Vector2D, CopyConstructor)
{
	Vector2D vec1(4, 6);
	Vector2D vec2(vec1);

	EXPECT_TRUE(vec2.x == vec1.x && vec2.y == vec1.y);
}

TEST(Vector2D, AssignmentOperator)
{
	Vector2D vec1(1, 2);
	Vector2D result = vec1;

	EXPECT_TRUE(vec1.x == result.x && vec1.y == result.y);

}

TEST(Vector2D, Swap)
{
	Vector2D vec1(1, 2);
	vec1.swap();
	EXPECT_TRUE(vec1.x == 2 && vec1.y == 1);

}

TEST(Vector2D, ArraySubscript)
{
	Vector2D vec1(1, 2);

	f32 x = vec1[0];
	f32 y = vec1[1];

	EXPECT_TRUE(x == 1 && y == 2);

}


TEST(Vector2D, Length)
{
	Vector2D vec1(1, 2);

	EXPECT_TRUE(vec1.length() == sqrt(5.00f));
}


//---------------------------------------Class methods finished here----------------------------


TEST(Vector2D, Add)
{
	Vector2D vec1(2, 5);
	Vector2D vec2(3, 6);

	Vector2D result(vec1.x + vec2.x, vec1.y + vec2.y);
	Vector2D result1 = vec1 + vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}

TEST(Vector2D, Subtract)
{
	Vector2D vec1(2, 5);
	Vector2D vec2(3, 6);

	Vector2D result(vec1.x - vec2.x, vec1.y - vec2.y);
	Vector2D result1 = vec1 - vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}


TEST(Vector2D, Multiply)
{
	Vector2D vec1(2, 5);
	Vector2D vec2(3, 2);

	Vector2D result(vec1.x * vec2.x, vec1.y * vec2.y);
	Vector2D result1 = vec1 * vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}


TEST(Vector2D, MultiplyScalar)
{
	Vector2D vec1(2, 5);
	float scaler = 2.0f;

	Vector2D result(vec1.x * scaler, vec1.y *scaler);
	Vector2D result1 = vec1 * scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}


TEST(Vector2D, Divide)
{
	Vector2D vec1(2, 5);
	Vector2D vec2(3, 2);

	Vector2D result(vec1.x / vec2.x, vec1.y / vec2.y);
	Vector2D result1 = vec1 / vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}


TEST(Vector2D, DivideScalar)
{
	Vector2D vec1(2, 5);
	float scaler = 2.0f;

	Vector2D result(vec1.x / scaler, vec1.y / scaler);
	Vector2D result1 = vec1 / scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}

TEST(Vector2D, IsEqual)
{
	Vector2D vec1(1, 2);
	Vector2D vec2(1, 2);

	EXPECT_TRUE(vec1 == vec2);
}

TEST(Vector2D, IsNotEqual)
{
	Vector2D vec1(1, 2);
	Vector2D vec2(1, 3);

	EXPECT_TRUE(vec1 != vec2);
}


TEST(Vector2D, Dot)
{
	Vector2D vec1(1, 2);
	Vector2D vec2(2, 1);
	float result = dot(vec1,vec2);
	float result1 = 1 * 2 + 2 * 1;
	
	EXPECT_TRUE(result == result1);
}

TEST(Vector2D, Cross)
{
	Vector2D vec1(1, 2);
	Vector2D vec2(2, 1);
	float result = cross(vec1, vec2);
	float result1 = 1 * 1 - 2 * 2;

	EXPECT_TRUE(result == result1);
}



TEST(Vector2D, Distance)
{
	Vector2D from(-7, -4);
	Vector2D to(17, 6.5);

	f32 dist = distance(from, to);

	EXPECT_TRUE(TestUtils::almostEqual(dist, 26.1964f));
}




