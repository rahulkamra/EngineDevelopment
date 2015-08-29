#pragma once
#include <gtest\gtest.h>
#include <Vector2.h>
#include "TestUtils.h"

using namespace math;

TEST(Vector2, Constructor)
{
	Vector2 vec1(1, 2);

	f32 arrayInit[2] = { 1.0f, 2.0f };
	Vector2 vec2{arrayInit};

	Vector2 vec3{1.0f,2.0f};

	EXPECT_TRUE(vec1.x == vec2.x &&  vec2.x  == vec3.x && vec1.y == vec2.y && vec2.y == vec3.y);
}


TEST(Vector2, AssignmentPlusEqual)
{
	Vector2 vec1(1, 2);
	Vector2 vec2(2, 1);

	vec2 += vec1;

	EXPECT_TRUE(vec2.x == 3 && vec2.y == 3);

}

TEST(Vector2, AssignmentPlusEqualScalar)
{
	Vector2 vec1(1, 2);
	f32 scaler = 2.0f;

	vec1 += scaler;

	EXPECT_TRUE(vec1.x == 3 && vec1.y == 4);

}

TEST(Vector2, AssignmentMinusEqualVector)
{
	Vector2 vec1(1, 2);
	Vector2 vec2(2, 1);

	vec2 -= vec1;
	EXPECT_TRUE(vec2.x == 1 && vec2.y == -1);

}

TEST(Vector2, AssignmentMinusEqualScalar)
{
	Vector2 vec1(3, 4);
	f32 scaler = 2.0f;

	vec1 -= scaler;

	EXPECT_TRUE(vec1.x == 1 && vec1.y == 2);

}

TEST(Vector2, AssignmentMultiplyEqualVector)
{
	Vector2 vec1(2, 2);
	Vector2 vec2(2, 3);

	vec2 *= vec1;
	EXPECT_TRUE(vec2.x == 4 && vec2.y == 6);

}

TEST(Vector2, AssignmentMultiplyEqualScalar)
{
	Vector2 vec1(3, 4);
	f32 scaler = 2.0f;

	vec1 *= scaler;

	EXPECT_TRUE(vec1.x == 6 && vec1.y == 8);

}

TEST(Vector2, AssignmentDivideEqualVector)
{
	Vector2 vec1(8, 12);
	Vector2 vec2(2, 3);

	vec1 /= vec2;
	EXPECT_TRUE(vec1.x == 4 && vec1.y == 4);

}

TEST(Vector2, AssignmentDivideEqualScalar)
{
	Vector2 vec1(4, 6);
	f32 scaler = 2.0f;

	vec1 /= scaler;

	EXPECT_TRUE(vec1.x == 2 && vec1.y == 3);

}

TEST(Vector2, CopyConstructor)
{
	Vector2 vec1(4, 6);
	Vector2 vec2(vec1);

	EXPECT_TRUE(vec2.x == vec1.x && vec2.y == vec1.y);
}

TEST(Vector2, AssignmentOperator)
{
	Vector2 vec1(1, 2);
	Vector2 result = vec1;

	EXPECT_TRUE(vec1.x == result.x && vec1.y == result.y);

}

TEST(Vector2, Swap)
{
	Vector2 vec1(1, 2);
	vec1.swap();
	EXPECT_TRUE(vec1.x == 2 && vec1.y == 1);

}

TEST(Vector2, ArraySubscript)
{
	Vector2 vec1(1, 2);

	f32 x = vec1[0];
	f32 y = vec1[1];

	EXPECT_TRUE(x == 1 && y == 2);

}


TEST(Vector2, Length)
{
	Vector2 vec1(1, 2);

	EXPECT_TRUE(vec1.length() == sqrt(5.00f));
}


//---------------------------------------Class methods finished here----------------------------


TEST(Vector2, Add)
{
	Vector2 vec1(2, 5);
	Vector2 vec2(3, 6);

	Vector2 result(vec1.x + vec2.x, vec1.y + vec2.y);
	Vector2 result1 = vec1 + vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}

TEST(Vector2, Subtract)
{
	Vector2 vec1(2, 5);
	Vector2 vec2(3, 6);

	Vector2 result(vec1.x - vec2.x, vec1.y - vec2.y);
	Vector2 result1 = vec1 - vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}

TEST(Vector2, Negate)
{
	Vector2 vec1(2, 5);
	Vector2 result = -vec1;

	EXPECT_TRUE(result.x == -2 && result.y == -5);
}


TEST(Vector2, Multiply)
{
	Vector2 vec1(2, 5);
	Vector2 vec2(3, 2);

	Vector2 result(vec1.x * vec2.x, vec1.y * vec2.y);
	Vector2 result1 = hadamardProduct(vec1 , vec2);

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}


TEST(Vector2, MultiplyScalar)
{
	Vector2 vec1(2, 5);
	f32 scaler = 2.0f;

	Vector2 result(vec1.x * scaler, vec1.y *scaler);
	Vector2 result1 = vec1 * scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}


TEST(Vector2, Divide)
{
	Vector2 vec1(2, 5);
	Vector2 vec2(3, 2);

	Vector2 result(vec1.x / vec2.x, vec1.y / vec2.y);
	Vector2 result1 = vec1 / vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}


TEST(Vector2, DivideScalar)
{
	Vector2 vec1(2, 5);
	f32 scaler = 2.0f;

	Vector2 result(vec1.x / scaler, vec1.y / scaler);
	Vector2 result1 = vec1 / scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}

TEST(Vector2, IsEqual)
{
	Vector2 vec1(1, 2);
	Vector2 vec2(1, 2);

	EXPECT_TRUE(vec1 == vec2);
}

TEST(Vector2, IsNotEqual)
{
	Vector2 vec1(1, 2);
	Vector2 vec2(1, 3);

	EXPECT_TRUE(vec1 != vec2);
}


TEST(Vector2, Dot)
{
	Vector2 vec1(1, 2);
	Vector2 vec2(2, 1);
	f32 result = dot(vec1,vec2);
	f32 result1 = 1 * 2 + 2 * 1;
	
	EXPECT_TRUE(result == result1);
}

TEST(Vector2, Cross)
{
	Vector2 vec1(1, 2);
	Vector2 vec2(2, 1);
	f32 result = cross(vec1, vec2);
	f32 result1 = 1 * 1 - 2 * 2;

	EXPECT_TRUE(result == result1);
}



TEST(Vector2, Distance)
{
	Vector2 from(-7, -4);
	Vector2 to(17, 6.5);

	f32 dist = distance(from, to);

	EXPECT_TRUE(TestUtils::almostEqual(dist, 26.1964f));
}


TEST(Vector2, NormalizeSelf)
{
	Vector2 vec1(3, 4);
	vec1.normalize();

	EXPECT_TRUE(vec1.x == 0.6f && vec1.y == 0.8f);
}


TEST(Vector2, ReturnNormalize)
{
	Vector2 vec1(3, 4);
	Vector2 vec2 = normalize(vec1);

	EXPECT_TRUE(vec2.x == 0.6f && vec2.y == 0.8f);
}

TEST(Vector2, Reflect)
{
	Vector2 vec1(3, 4);
	Vector2 vec2(0, 1);
	Vector2 vec3 = reflect(vec1, vec2);
	
	EXPECT_TRUE(vec3.x == -3.0f && vec3.y == 4.0f);
}

TEST(Vector2, AngleBetween)
{
	Vector2 vec1(2, 3);
	Vector2 vec2(3, 4);
	f32 result = angle(vec1, vec2);

	EXPECT_TRUE(TestUtils::almostEqual(result, 0.05549850524f));
}

