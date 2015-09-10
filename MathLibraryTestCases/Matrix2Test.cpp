#pragma once
#include <gtest\gtest.h>
#include <Matrix2.h>
#include <Vector2.h>
#include "TestUtils.h"

using namespace math;

TEST(Matrix2, Constrctor)
{
	
	Matrix2 matrix{ Vector2{1,2} , Vector2{ 3,4 } };
	EXPECT_TRUE((matrix.x == Vector2{ 1,2 }) && (matrix.y == Vector2{ 3 , 4 }));
}

TEST(Matrix2, CreateMatrixFromRotation)
{
	Matrix2 matrixZero = Matrix2::createRotateMatrix(0);
	EXPECT_TRUE(TestUtils::almostEqual(matrixZero.x.x, 1.0f));
	EXPECT_TRUE(TestUtils::almostEqual(matrixZero.x.y, 0.0f));
	EXPECT_TRUE(TestUtils::almostEqual(matrixZero.y.x, 0.0f));
	EXPECT_TRUE(TestUtils::almostEqual(matrixZero.y.y, 1.0f));


	Matrix2 matrixPiby4 = Matrix2::createRotateMatrix(MATH_PI_4);
	EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.x.x, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.x.y, -MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.y.x, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixPiby4.y.y, MATH_SQRT1_2));


	Matrix2 matrix3Piby4 = Matrix2::createRotateMatrix(MATH_PI_4*3);
	EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.x.x, -MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.x.y, -MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.y.x, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrix3Piby4.y.y, -MATH_SQRT1_2));


	Matrix2 matrixnegativePiBy4 = Matrix2::createRotateMatrix(-MATH_PI_4);
	EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.x.x, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.x.y, MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.y.x, -MATH_SQRT1_2));
	EXPECT_TRUE(TestUtils::almostEqual(matrixnegativePiBy4.y.y, MATH_SQRT1_2));


}

TEST(Matrix2, ArraySubscript)
{
	Vector2 a1 = Vector2(1, 2);
	Vector2 a2 = Vector2(3, 1);

	Matrix2 matrix( a1 , a2 );

	Vector2 v1 = matrix[0];
	Vector2 v2 = matrix[1];

	EXPECT_TRUE(a1 == v1 && a2 == v2);

}


TEST(Matrix2, Assignment)
{
	Matrix2 matrix{ Vector2{ 1,2 } , Vector2{ 3,4 } };
	Matrix2 matrix2 = matrix;

	EXPECT_TRUE(matrix == matrix2);

	EXPECT_TRUE(matrix.x == matrix2.x);
	EXPECT_TRUE(matrix.y == matrix2.y);
}



TEST(Matrix2, PlusOperator)
{
	Matrix2 matrix1{ Vector2{ 1,2} , Vector2{ 3,4}};
	Matrix2 matrix2{ Vector2{ 3,2} , Vector2{ 5,3}};
	Matrix2 sum = matrix1 + matrix2;

	Matrix2 sum2{ Vector2{ 4,4} , Vector2{ 8,7}};

	EXPECT_TRUE(sum == sum2);
}

TEST(Matrix2, PlusEqualOperator)
{
	Matrix2 matrix1{ Vector2{ 1,2 } , Vector2{ 3,4 } };
	Matrix2 matrix2{ Vector2{ 3,2 } , Vector2{ 5,3 } };
	matrix2 += matrix1;

	Matrix2 sum2{ Vector2{ 4,4 } , Vector2{ 8,7 } };

	EXPECT_TRUE(matrix2 == sum2);
}

TEST(Matrix2, SubtractOperator)
{
	Matrix2 matrix1{ Vector2{ 1,2} , Vector2{ 3,4}};
	Matrix2 matrix2{ Vector2{ 3,2} , Vector2{ 5,3}};
	Matrix2 sub = matrix1 - matrix2;

	Matrix2 sub2{ Vector2{ -2,0} , Vector2{ -2,1}};

	EXPECT_TRUE(sub == sub2);
}

TEST(Matrix2, SubtractEqualOperator)
{
	Matrix2 matrix1{ Vector2{ 1,2 } , Vector2{ 3,4 } };
	Matrix2 matrix2{ Vector2{ 3,2 } , Vector2{ 5,3 } };
	matrix1 -= matrix2;

	Matrix2 sub2{ Vector2{ -2,0 } , Vector2{ -2,1 } };

	EXPECT_TRUE(matrix1 == sub2);
}

TEST(Matrix2, MatrixMultiplicationScaler)
{
	Matrix2 matrix1{ Vector2{ 1,2} , Vector2{ 4,5,}};

	Matrix2 result1 = matrix1 * 2;
	Matrix2 result2{ Vector2{ 2,4} , Vector2{ 8,10}};

	EXPECT_TRUE(result1 == result2);
}


TEST(Matrix2, MatrixMultiplication)
{
	Matrix2 matrix1(Vector2{ 1 , 3 }, Vector2{ 2 , 4 });
	Matrix2 matrix2(Vector2{ 5 , 7 }, Vector2{ 6 , 8 });

	Matrix2 matrix3 = matrix1 * matrix2;
	Matrix2 matrix4(Vector2{ 19 , 43 }, Vector2{ 22 , 50 });

	EXPECT_TRUE(matrix3 == matrix4);
}

TEST(Matrix2, MultiplyWithVector)
{
	Matrix2 matrix(Vector2{ 2 , 4 }, Vector2{ -3 , 5 });
	Vector2 vec2(3, 9);
	Vector2 result = matrix * vec2;
	EXPECT_TRUE(result.x == -21 && result.y == 57);
}

TEST(Matrix2, MatrixDivideScaler)
{
	Matrix2 matrix1{ Vector2{ 1,2} , Vector2{ 4,5}};

	Matrix2 result1 = matrix1 / 2;
	Matrix2 result2{ Vector2{ (f32)1 / 2 , (f32)1 } , Vector2{ (f32)4 / 2,(f32)5 / 2}};

	EXPECT_TRUE(TestUtils::almostEqual(result1, result2));
}

TEST(Matrix2, MatrixDivideEqualScaler)
{
	Matrix2 matrix1{ Vector2{ 1,2 } , Vector2{ 4,5 } };

	matrix1 /= 2;
	Matrix2 result2{ Vector2{ (f32)1 / 2 , (f32)1 } , Vector2{ (f32)4 / 2,(f32)5 / 2 } };

	EXPECT_TRUE(TestUtils::almostEqual(matrix1, result2));
}

TEST(Matrix2, Equal)
{
	Matrix2 matrix{ Vector2{ 2,2 } , Vector2{ 3,4 } };
	Matrix2 matrix2{ Vector2{ 2,2 } , Vector2{ 3,4 } };
	EXPECT_TRUE(matrix == matrix2);
}

TEST(Matrix2, NotEqual)
{
	Matrix2 matrix{ Vector2{ 1,2 } , Vector2{ 3,4 } };
	Matrix2 matrix2{ Vector2{ 2,2 } , Vector2{ 3,4 } };

	EXPECT_TRUE(matrix != matrix2);
}

TEST(Matrix2, Transpose)
{
	Matrix2 matrix1{ Vector2{ 1,2} , Vector2{ 4,5}};
	Matrix2 transposed = transpose(matrix1);

	Matrix2 result{ { 1 , 4} ,{ 2 , 5}};
	EXPECT_TRUE(result == transposed);
}


TEST(Matrix2, Determinant)
{
	Matrix2 matrix(Vector2{ 5 , -1 }, Vector2{ 3 , 4 });
	EXPECT_TRUE(determinant(matrix) == 23);
}

TEST(Matrix2, Inverse)
{
	Matrix2 matrix(Vector2{ 3 , -7 }, Vector2{ 5 , 2 });
	Matrix2 inverseMatrix = inverse(matrix);

	EXPECT_TRUE(TestUtils::almostEqual(inverseMatrix[0][0], 2 / 41.0f));
	EXPECT_TRUE(TestUtils::almostEqual(inverseMatrix[0][1], 7 / 41.0f));

	EXPECT_TRUE(TestUtils::almostEqual(inverseMatrix[1][0], -5 / 41.0f));
	EXPECT_TRUE(TestUtils::almostEqual(inverseMatrix[1][1], 3 / 41.0f));



	//M*M(Inv) = Identity
	Matrix2 matrix2(Vector2{ 3 , -7 }, Vector2{ 5 , 2 });
	Matrix2 tempInverse = inverse(matrix2);

	Matrix2  productMatrix = matrix2 * tempInverse;
	EXPECT_TRUE(determinant(productMatrix) == 1.0f);


}
