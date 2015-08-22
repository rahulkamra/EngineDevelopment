#pragma once
#include <gtest\gtest.h>
#include <Matrix2D.h>
#include <Vector2D.h>
#include "TestUtils.h"

using namespace math;

TEST(Matrix2D, MultiplyWithVector)
{
	Matrix2D matrix(Vector2D{ 2 , 4 } , Vector2D{ -3 , 5 });
	Vector2D vec2(3, 9);
	Vector2D result = matrix * vec2; 

	EXPECT_TRUE(result.x == -21 && result.y == 57);
}


TEST(Matrix2D, CreateMatrixFromRotation)
{
	Matrix2D matrixZero = Matrix2D::createRotateMatrix(0);
	//EXPECT_TRUE(TestUtils::almostEqual(matrixZero.x.x, 1));
	//EXPECT_TRUE(TestUtils::almostEqual(matrixZero.b, 0));
	//EXPECT_TRUE(TestUtils::almostEqual(matrixZero.c, 0));
	//EXPECT_TRUE(TestUtils::almostEqual(matrixZero.d, 1));


	Matrix2D matrixPiby4 = Matrix2D::createRotateMatrix(MATH_PI_4);
	//EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.a, MATH_SQRT1_2));
	//EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.b, -MATH_SQRT1_2));
	//EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.c, MATH_SQRT1_2));
	//EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.d, MATH_SQRT1_2));


	Matrix2D matrix3Piby4 = Matrix2D::createRotateMatrix(MATH_PI_4*3);
	//EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.a, -MATH_SQRT1_2));
	//EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.b, -MATH_SQRT1_2));
	//EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.c, MATH_SQRT1_2));
	//EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.d, -MATH_SQRT1_2));


	Matrix2D matrixnegativePiBy4 = Matrix2D::createRotateMatrix(-MATH_PI_4);
	//EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.a, MATH_SQRT1_2));
	//EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.b, MATH_SQRT1_2));
	//EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.c, -MATH_SQRT1_2));
	//EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.d, MATH_SQRT1_2));


}

TEST(Matrix2D, ArraySubscript)
{
	Vector2D a1 = Vector2D(1, 2);
	Vector2D a2 = Vector2D(3, 1);

	Matrix2D matrix( a1 , a2 );

	Vector2D v1 = matrix[0];
	Vector2D v2 = matrix[1];

	EXPECT_TRUE(a1 == v1 && a2 == v2);

}


TEST(Matrix2D, SetColumn)
{
	//Matrix2D matrix(10, 3,
				  //  40, 1);

	//matrix.setColumn(0, Vector2D(12,13));

	//EXPECT_TRUE(matrix.a == 12 && matrix.c == 13);
	//matrix.setRow(0, Vector2D(19, 13));

	//EXPECT_TRUE(matrix.a == 19 && matrix.b == 13);

}

