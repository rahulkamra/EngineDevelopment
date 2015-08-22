#pragma once
#include <gtest\gtest.h>
#include <Matrix2D.h>
#include <Vector2D.h>
#include "TestUtils.h"

using namespace math;

TEST(Matrix2D, Constrctor)
{
	Matrix2D matrix{ Vector2D{1,2} , Vector2D{ 3,4 } };
	EXPECT_TRUE((matrix.x == Vector2D{ 1,2 }) && (matrix.y == Vector2D{ 3 , 4 }));
}

TEST(Matrix2D, CreateMatrixFromRotation)
{
	Matrix2D matrixZero = Matrix2D::createRotateMatrix(0);
	EXPECT_TRUE(TestUtils::almostEqual(matrixZero.x.x, 1.0f));
	EXPECT_TRUE(TestUtils::almostEqual(matrixZero.x.y, 0.0f));
	EXPECT_TRUE(TestUtils::almostEqual(matrixZero.y.x, 0.0f));
	EXPECT_TRUE(TestUtils::almostEqual(matrixZero.y.y, 1.0f));


	Matrix2D matrixPiby4 = Matrix2D::createRotateMatrix(MATH_PI_4);
	EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.x.x, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.x.y, -MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.y.x, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.y.y, MATH_SQRT1_2));


	Matrix2D matrix3Piby4 = Matrix2D::createRotateMatrix(MATH_PI_4*3);
	EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.x.x, -MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.x.y, -MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.y.x, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.y.y, -MATH_SQRT1_2));


	Matrix2D matrixnegativePiBy4 = Matrix2D::createRotateMatrix(-MATH_PI_4);
	EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.x.x, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.x.y, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.y.x, -MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.y.y, MATH_SQRT1_2));


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


TEST(Matrix2D, Assignment)
{
	Matrix2D matrix{ Vector2D{ 1,2 } , Vector2D{ 3,4 } };
	Matrix2D matrix2 = matrix;

	EXPECT_TRUE(matrix == matrix2);

	EXPECT_TRUE(matrix.x == matrix2.x);
	EXPECT_TRUE(matrix.y == matrix2.y);
}

TEST(Matrix2D, Equal)
{
	Matrix2D matrix{ Vector2D{ 2,2 } , Vector2D{ 3,4 } };
	Matrix2D matrix2{ Vector2D{ 2,2 } , Vector2D{ 3,4 } };
	EXPECT_TRUE(matrix == matrix2);
}

TEST(Matrix2D, NotEqual)
{
	Matrix2D matrix{ Vector2D{ 1,2 } , Vector2D{ 3,4 } };
	Matrix2D matrix2{ Vector2D{ 2,2 } , Vector2D{ 3,4 } };

	EXPECT_TRUE(matrix != matrix2);
}



TEST(Matrix2D, MultiplyWithVector)
{
	Matrix2D matrix(Vector2D{ 2 , 4 }, Vector2D{ -3 , 5 });
	Vector2D vec2(3, 9);
	Vector2D result = matrix * vec2;

	EXPECT_TRUE(result.x == -21 && result.y == 57);
}

