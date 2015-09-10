#pragma once
#include <gtest\gtest.h>
#include <Matrix4.h>
#include <Vector4.h>
#include "TestUtils.h"

using namespace math;

TEST(Matrix4, Constructor)
{
	Matrix4 matrix{ { 1,2 ,3 ,4 } , { 5 ,6 , 7 , 8} , { 9 , 10,11,12 } , { 13 , 14, 15 , 16 } };
	EXPECT_TRUE((matrix.x == Vector4{ 1,2 ,3,4 }) && (matrix.y == Vector4{ 5 ,6 , 7 , 8 }) && (matrix.z == Vector4(9, 10, 11, 12) && matrix.w == Vector4(13, 14, 15, 16)));
}

TEST(Matrix4, ArraySubscript)
{
	Vector4 a1 = Vector4(1, 2, 3, 6);
	Vector4 a2 = Vector4(3, 1, 2, 0);
	Vector4 a3 = Vector4(4, 5, 6, 7);
	Vector4 a4 = Vector4(3, 1, 3, 4);

	Matrix4 matrix(a1, a2, a3 , a4);

	Vector4 v1 = matrix[0];
	Vector4 v2 = matrix[1];
	Vector4 v3 = matrix[2];
	Vector4 v4 = matrix[3];

	EXPECT_TRUE(a1 == v1 && a2 == v2 && a3 == v3 && a4 == v4);
}


TEST(Matrix4, Assignment)
{
	Matrix4 matrix{{ 1,2 ,3,5 } ,{ 3,4 ,5 ,1 } ,{ 6 , 7 , 8 ,6}, {3 ,4 ,1, 2}};
	Matrix4 matrix2 = matrix;

	EXPECT_TRUE(matrix == matrix2);

	EXPECT_TRUE(matrix.x == matrix2.x);
	EXPECT_TRUE(matrix.y == matrix2.y);
	EXPECT_TRUE(matrix.z == matrix2.z);
	EXPECT_TRUE(matrix.w == matrix2.w);
}

TEST(Matrix4, PlusOperator)
{
	Matrix4 matrix1{{ 1,2 ,3, 5 } ,{ 3,4 ,5,8 } ,{ 6 , 7 , 8 ,2} ,{ 2 , 4 , 5 ,1 } };
	Matrix4 matrix2{ { 1,3 ,2, 5 } ,{ 1,4 ,5,3 } ,{ 1 , 3 , 1 ,2 } ,{ 2 , 7 , 8 ,1 } };
	Matrix4 sum = matrix1 + matrix2;

	Matrix4 sum2{{ 2,5,5,10 } ,{ 4,8,10,11} ,{7,10,9,4} ,{4,11,13,2}};

	EXPECT_TRUE(sum == sum2);
}

TEST(Matrix4, PlusEqualOperator)
{
	Matrix4 matrix1{ { 1,2 ,3, 5 } ,{ 3,4 ,5,8 } ,{ 6 , 7 , 8 ,2 } ,{ 2 , 4 , 5 ,1 } };
	Matrix4 matrix2{ { 1,3 ,2, 5 } ,{ 1,4 ,5,3 } ,{ 1 , 3 , 1 ,2 } ,{ 2 , 7 , 8 ,1 } };
	matrix1 += matrix2;

	Matrix4 sum2{ { 2,5,5,10 } ,{ 4,8,10,11 } ,{ 7,10,9,4 } ,{ 4,11,13,2 } };

	EXPECT_TRUE(matrix1 == sum2);
}

TEST(Matrix4, SubtractOperator)
{
	Matrix4 matrix1{ { 1,2 ,3, 5 } ,{ 3,4 ,5,8 } ,{ 6 , 7 , 8 ,2 } ,{ 2 , 4 , 5 ,1 } };
	Matrix4 matrix2{ { 1,3 ,2, 5 } ,{ 1,4 ,5,3 } ,{ 1 , 3 , 1 ,2 } ,{ 2 , 7 , 8 ,1 } };
	Matrix4 sub = matrix1 - matrix2;

	Matrix4 sub2{ { 0,-1,1,0 } ,{2,0,0,5} ,{5,4,7,0 },{0,-3,-3,0} };

	EXPECT_TRUE(sub == sub2);
}

TEST(Matrix4, SubtractEqualOperator)
{
	Matrix4 matrix1{ { 1,2 ,3, 5 } ,{ 3,4 ,5,8 } ,{ 6 , 7 , 8 ,2 } ,{ 2 , 4 , 5 ,1 } };
	Matrix4 matrix2{ { 1,3 ,2, 5 } ,{ 1,4 ,5,3 } ,{ 1 , 3 , 1 ,2 } ,{ 2 , 7 , 8 ,1 } };
	matrix1 -= matrix2;

	Matrix4 sub2{ { 0,-1,1,0 } ,{ 2,0,0,5 } ,{ 5,4,7,0 },{ 0,-3,-3,0 } };

	EXPECT_TRUE(matrix1 == sub2);
}


TEST(Matrix4, MatrixMultiplicationScaler)
{
	Matrix4 matrix1{ { 1,2 ,3, 5 } ,{ 3,4 ,5,8 } ,{ 6 , 7 , 8 ,2 } ,{ 2 , 4 , 5 ,1 } };

	Matrix4 result1 = matrix1 * 2;
	Matrix4 result2{{ 2,4,6,10 } ,{ 6,8,10,16} ,{ 12,14,16,4} ,{ 4,8,10,2}};

	EXPECT_TRUE(result1 == result2);
}


TEST(Matrix4, MatrixMultiplication)
{
	Matrix4 matrix1{{ 1,2 ,3 ,4 },{ 4,5,6 , 7 },{ 7,8,9,10 },{3,2, 1,-1 }};
	Matrix4 matrix2{ {3,1,2,0},{ 2,1,0,5},{ 6,3,1,4},{3,2,1,-1 }};

	Matrix4 result1 = matrix1 * matrix2;
	Matrix4 result2{ { 21,27 ,33,39 },{ 21,19,17,10},{ 37,43,49,51},{15,22,29,37}};	

	EXPECT_TRUE(result1 == result2);
}



TEST(Matrix4, MultiplyWithVector)
{//
	Matrix4 matrix1{ { 1,2 ,3 ,4 },{ 4,5,6 , 7 },{ 7,8,9,10 },{ 3,2, 1,-1 } };
	Vector4 vec{ 2,3,4,1 };

	Vector4 result1 = matrix1 * vec;

	Vector4 result2 = Vector4(45, 53, 61 , 68);

	EXPECT_TRUE(result1 == result2);
}

TEST(Matrix4, MatrixDivideScaler)
{
	Matrix4 matrix1{{ 1,2 ,3,4 } ,{ 4,5,6,7 } ,{ 7,8,9,10 },{ 11,12,13,14 } };

	Matrix4 result1 = matrix1 / 2;
	Matrix4 result2{ Vector4{ (f32)1/2 , (f32)1, (f32)3/2 ,(f32)2} , Vector4{ (f32)4/2,(f32)5/2,(f32)6/2,(f32)7/2 } , Vector4{ (f32)7/2,(f32)8/2,(f32)9/2,f32(10/2) } , { (f32)11/2,(f32)12/2,(f32)13/2,(f32)14/2 } };

	EXPECT_TRUE(TestUtils::almostEqual(result1, result2));
}

TEST(Matrix4, MatrixDivideEqualScaler)
{
	Matrix4 matrix1{ { 1,2 ,3,4 } ,{ 4,5,6,7 } ,{ 7,8,9,10 },{ 11,12,13,14 } };

	matrix1 /= 2;
	Matrix4 result2{ Vector4{ (f32)1 / 2 , (f32)1, (f32)3 / 2 ,(f32)2 } , Vector4{ (f32)4 / 2,(f32)5 / 2,(f32)6 / 2,(f32)7 / 2 } , Vector4{ (f32)7 / 2,(f32)8 / 2,(f32)9 / 2,f32(10 / 2) } ,{ (f32)11 / 2,(f32)12 / 2,(f32)13 / 2,(f32)14 / 2 } };

	EXPECT_TRUE(TestUtils::almostEqual(matrix1, result2));
}



TEST(Matrix4, Equal)
{
	Matrix4 matrix1{{ 1,2 ,3,4 } ,{ 3,4 ,5 ,6} ,{ 6 , 7 , -8 ,9} ,{ 16 , 17 , -18 ,0 } };
	Matrix4 matrix2{{ 1,2 ,3,4 } ,{ 3,4 ,5 ,6} ,{ 6 , 7 , -8 ,9} ,{ 16 , 17 , -18 ,0 } };

	EXPECT_TRUE(matrix1 == matrix2);
}

TEST(Matrix4, NotEqual)
{
	Matrix4 matrix1{ { 1,-2 ,3,4 } ,{ 3,4 ,0 ,6 } ,{ 6 , 7 , -8 ,9 } ,{ 16 , -17 , -18 ,0 } };
	Matrix4 matrix2{ { 1,2 ,3,4 } ,{ 3,-4 ,5 ,6 } ,{ 6 , 1 , -8 ,9 } ,{ 16 , 17 , -18 ,0 } };

	EXPECT_TRUE(matrix1 != matrix2);
}

TEST(Matrix4, Transpose)
{
	Matrix4 matrix1{{ 1,2,3,4 } ,{5,6,7,8 } ,{ 9,10,11,12 } ,{ 13,14,15,16 } };
	Matrix4 transposed = transpose(matrix1);

	Matrix4 result{{ 1,5,9,13 } ,{ 2,6,10,14 } ,{ 3,7,11,15},{ 4,8,12,16 }};
	EXPECT_TRUE(result == transposed);
}


TEST(Matrix4, Determinant)
{
	Matrix4 matrix1{ { 6 , 4 , -1 , 8} ,{ 0 , 13 , 0 , 6} ,{ -3 , 6 , 7 , 0 } ,{ 5 , -8 , 4 , 2} };
	f32 detMat1= determinant(matrix1);
	EXPECT_TRUE(detMat1 == 170);

	Matrix4 matrix2{ {1,1,2,-1 } ,{ 2,2,7,4} ,{ 2,4,5,-6} ,{ 1,2,2,3}};
	f32 detMat2 = determinant(matrix2);
	EXPECT_TRUE(detMat2 == -42);
}

TEST(Matrix4, Inverse)
{
	Matrix4 matrix1{ { 1,0,2,2} ,{ 0,2,1,0} ,{ 0,1,0,1} ,{ 1,2,1,4} };
	Matrix4 invMatrix = inverse(matrix1);
	Matrix4 resultInv{ {-2,1,-8,3} , {-0.5,0.5,-1,0.5},{1,0,2,-1},{0.5,-0.5,2,-0.5} };
	EXPECT_TRUE(resultInv == invMatrix);

	Matrix4 product = matrix1 * invMatrix;
	EXPECT_TRUE(determinant(product) == 1.0f);
	
}