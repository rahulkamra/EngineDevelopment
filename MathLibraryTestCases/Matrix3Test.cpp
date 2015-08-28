#pragma once
#include <gtest\gtest.h>
#include <Matrix3.h>
#include <Vector3.h>
#include "TestUtils.h"

using namespace math;

TEST(Matrix3, Constrctor)
{
	Matrix3 matrix{ Vector3{ 1,2 ,3} , Vector3{ 4,5,6 } , Vector3{ 7,8,9} };
	EXPECT_TRUE((matrix.x == Vector3{ 1,2 ,3}) && (matrix.y == Vector3{ 4 , 5 ,6}) && (matrix.z == Vector3(7 , 8 , 9)));
}

TEST(Matrix3, ArraySubscript)
{
	Vector3 a1 = Vector3(1, 2 , 3);
	Vector3 a2 = Vector3(3, 1 , 2);
	Vector3 a3 = Vector3(4, 5, 6);

	Matrix3 matrix(a1, a2 , a3);

	Vector3 v1 = matrix[0];
	Vector3 v2 = matrix[1];
	Vector3 v3 = matrix[2];

	EXPECT_TRUE(a1 == v1 && a2 == v2 && a3 == v3);
}


TEST(Matrix3, Assignment)
{
	Matrix3 matrix{ Vector3{ 1,2 ,3 } , Vector3{ 3,4 ,5} , Vector3{ 6 , 7 , 8 }};
	Matrix3 matrix2 = matrix;

	EXPECT_TRUE(matrix == matrix2);

	EXPECT_TRUE(matrix.x == matrix2.x);
	EXPECT_TRUE(matrix.y == matrix2.y);
	EXPECT_TRUE(matrix.z == matrix2.z);
}

TEST(Matrix3, PlusOperator)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 3,4 ,5 } , Vector3{ 6 , 7 , 8 } };
	Matrix3 matrix2{ Vector3{ 3,2 ,1 } , Vector3{ 5,3,4} , Vector3{ 8,7,6} };
	Matrix3 sum = matrix1 + matrix2;

	Matrix3 sum2{ Vector3{ 4,4 ,4 } , Vector3{ 8,7,9 } , Vector3{ 14,14,14 } };

	EXPECT_TRUE(sum == sum2);
}

TEST(Matrix3, PlusEqualOperator)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 3,4 ,5 } , Vector3{ 6 , 7 , 8 } };
	Matrix3 matrix2{ Vector3{ 3,2 ,1 } , Vector3{ 5,3,4 } , Vector3{ 8,7,6 } };
	matrix2 += matrix1;

	Matrix3 sum2{ Vector3{ 4,4 ,4 } , Vector3{ 8,7,9 } , Vector3{ 14,14,14 } };

	EXPECT_TRUE(matrix2 == sum2);
}

TEST(Matrix3, SubtractOperator)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 3,4 ,5 } , Vector3{ 6 , 7 , 8 } };
	Matrix3 matrix2{ Vector3{ 3,2 ,1 } , Vector3{ 5,3,4 } , Vector3{ 8,7,6 } };
	Matrix3 sub = matrix1 - matrix2;

	Matrix3 sub2{ Vector3{ -2,0 ,2 } , Vector3{ -2,1,1 } , Vector3{ -2,0,2 } };

	EXPECT_TRUE(sub == sub2);
}

TEST(Matrix3, SubtractEqualOperator)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 3,4 ,5 } , Vector3{ 6 , 7 , 8 } };
	Matrix3 matrix2{ Vector3{ 3,2 ,1 } , Vector3{ 5,3,4 } , Vector3{ 8,7,6 } };
	matrix1 -= matrix2;

	Matrix3 sub2{ Vector3{ -2,0 ,2 } , Vector3{ -2,1,1 } , Vector3{ -2,0,2 } };

	EXPECT_TRUE(matrix1 == sub2);
}


TEST(Matrix3, MatrixMultiplicationScaler)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 4,5,6 } , Vector3{ 7,8,9 } };
	
	Matrix3 result1 = matrix1 * 2;
	Matrix3 result2{ Vector3{ 2,4,6 } , Vector3{ 8,10,12 } , Vector3{ 14,16,18} };

	EXPECT_TRUE(result1 == result2);
}


TEST(Matrix3, MatrixMultiplication)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 4,5,6 } , Vector3{ 7,8,9 } };
	Matrix3 matrix2{ Vector3{ 3,1 ,2 } , Vector3{ 2,1,5 } , Vector3{ 6,3,1 } };

	Matrix3 result1 = matrix1 * matrix2;
	Matrix3 result2{ Vector3{ 21,27 ,33 } , Vector3{ 41,49,57 } , Vector3{ 25,35,45 } };

	EXPECT_TRUE(result1 == result2);
}



TEST(Matrix3, MultiplyWithVector)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 4,5,6 } , Vector3{ 7,8,9 } };
	Vector3 vec{2,3,4};

	Vector3 result1 = matrix1 * vec;

	Vector3 result2 = Vector3(42,51,60);

	EXPECT_TRUE(result1 == result2);
}

TEST(Matrix3, MatrixDivideScaler)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 4,5,6 } , Vector3{ 7,8,9 } };

	Matrix3 result1 = matrix1 / 2;
	Matrix3 result2{ Vector3{ (f32)1 / 2 , (f32)1, (f32)3 / 2 } , Vector3{ (f32)4 / 2,(f32)5 / 2,(f32)6 / 2 } , Vector3{ (f32)7 / 2,(f32)8 / 2,(f32)9 / 2 } };

	EXPECT_TRUE(TestUtils::almostEqual(result1, result2));
}

TEST(Matrix3, MatrixDivideEqualScaler)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 4,5,6 } , Vector3{ 7,8,9 } };

	matrix1 /= 2;
	Matrix3 result2{ Vector3{ (f32)1 / 2 , (f32)1, (f32)3 / 2 } , Vector3{ (f32)4 / 2,(f32)5 / 2,(f32)6 / 2 } , Vector3{ (f32)7 / 2,(f32)8 / 2,(f32)9 / 2 } };

	EXPECT_TRUE(TestUtils::almostEqual(matrix1, result2));
}



TEST(Matrix3, Equal)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 3,4 ,5 } , Vector3{ 6 , 7 , -8 } };
	Matrix3 matrix2{ Vector3{ 1,2 ,3 } , Vector3{ 3,4 ,5 } , Vector3{ 6 , 7 , -8 } };

	EXPECT_TRUE(matrix1 == matrix2);
}

TEST(Matrix3, NotEqual)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 3,4 ,-5 } , Vector3{ 6 , 7 , -8 } };
	Matrix3 matrix2{ Vector3{ 1,2 ,3 } , Vector3{ 3,4 ,5 } , Vector3{ 6 , 7 , -8 } };

	EXPECT_TRUE(matrix1 != matrix2);
}

TEST(Matrix3, Transpose)
{
	Matrix3 matrix1{ Vector3{ 1,2 ,3 } , Vector3{ 4,5,6 } , Vector3{7,8,9} };
	Matrix3 transposed = transpose(matrix1);

	Matrix3 result{ {1 , 4 ,7 } ,{ 2 , 5 , 8} ,{ 3 , 6 , 9 } };
	EXPECT_TRUE(result == transposed);
}


TEST(Matrix3, Determinant)
{
	Matrix3 matrix1{ Vector3{ 4,4 ,-2 } , Vector3{ -1,5,0 } , Vector3{ 1,3, 0 } };
	f32 value = determinant(matrix1);
	EXPECT_TRUE(value == 16);

	Matrix3 matrix2{ Vector3{ 1,2 ,3 } , Vector3{ 4,5,6 } , Vector3{ 7,8,9 } };
	f32 value2 = determinant(matrix2);
	EXPECT_TRUE(value2 == 0);

}

TEST(Matrix3, Inverse)
{
	Matrix3 matrix1{ Vector3{ 1,0 , 1 } , Vector3{ 0,2,1 } , Vector3{ 1,1, 1 } };
	Matrix3 result1{ Vector3{ -1  ,-1 , 2 } , Vector3{ -1 , 0 , 1} ,Vector3{ 2 , 1 , -2 } };


	Matrix3 matrix2{ Vector3{ 1,0 , 3 } , Vector3{ 5,2,0 } , Vector3{ 0,4, 0 } };
	Matrix3 result2{ Vector3{ 0  , (f32)1/5 , (f32)-1/10 } , Vector3{ 0 , 0 , (f32)1/4 } ,Vector3{ (f32)1/3 ,(f32)-1/15 ,(f32)1/30 } };
	
	EXPECT_TRUE(TestUtils::almostEqual(inverse(matrix1) , result1));
	EXPECT_TRUE(TestUtils::almostEqual(inverse(matrix2), result2));
}