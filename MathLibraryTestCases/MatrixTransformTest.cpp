#pragma once
#include <gtest\gtest.h>
#include <Matrix4.h>
#include <MatrixTransform.h>
using namespace math;


TEST(Matrix4, lookAt)
{
	Matrix4 look1 =  lookAt({ 1,2,3 }, { 4,5,6 }, { 0,1,0 });
	Matrix4 look2 = lookAt2({ 1,2,3 }, { 4,5,6 }, { 0,1,0 });

	std::cout << look1;
	std::cout << look2;
	EXPECT_TRUE(look1 == look2);
}
