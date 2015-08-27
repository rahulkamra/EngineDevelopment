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

TEST(Matrix3, CrossProduct)
{
	
}


TEST(Matrix3, MultiplyWithVector)
{
	
}


TEST(Matrix3, Determinant)
{
	
}

TEST(Matrix3, Inverse)
{
	


}