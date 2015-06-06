#pragma once
#include <gtest\gtest.h>
#include <Vector2D.h>

using namespace math;

TEST(Vector2D , Add)
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
	float scaler = 2.0f;

	Vector2D result(vec1.x * scaler, vec1.y *scaler);
	Vector2D result1 = vec1 * scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}





TEST(Vector2D, Divide)
{
	Vector2D vec1(2, 5);
	float scaler = 2.0f;

	Vector2D result(vec1.x / scaler, vec1.y /scaler);
	Vector2D result1 = vec1 / scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}


TEST(Vector2D, Dot)
{
	Vector2D vec1(1, 2);
	Vector2D vec2(2, 1);
	float result = vec1.dot(&vec2);
	float result1 = 1 * 2 + 2 * 1;
	
	EXPECT_TRUE(result == result1);
}



TEST(Vector2D, AssignmentOperator)
{
	Vector2D vec1(1, 2);
	Vector2D result = vec1;
	
	EXPECT_TRUE(vec1.x == result.x && vec1.y == result.y);

}


TEST(Vector2D, AssignmentPlusEqual)
{
	Vector2D vec1(1, 2);
	Vector2D vec2(2, 1);
	
	vec2 += vec1;

	EXPECT_TRUE(vec2.x == 3 && vec2.y == 3);

}


TEST(Vector2D, AssignmentMinusEqual)
{
	Vector2D vec1(1, 2);
	Vector2D vec2(2, 1);

	vec2 -= vec1;
	EXPECT_TRUE(vec2.x == 1 && vec2.y == -1);

}


