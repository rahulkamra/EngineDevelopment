#pragma once
#include <Matrix4.h>
#include <Vector3.h>

namespace math
{
	//https://www.youtube.com/watch?v=s9FhcvjM7Hk
	Matrix4 lookAt(Vector3 eye, Vector3 target , Vector3 up)
	{
		//we need three basis vector to get this. // right , up , backward(for right hand coordinate system)
		Matrix4 result;

		Vector3 backAxis = normalize(eye - target);
		Vector3 rightAxis = normalize(cross(up , backAxis));
		Vector3 upAxis = normalize(cross(backAxis,rightAxis));

		result[0][0] = rightAxis.x;
		result[1][0] = rightAxis.y;
		result[2][0] = rightAxis.z;

		result[0][1] = upAxis.x;
		result[1][1] = upAxis.y;
		result[2][1] = upAxis.z;

		result[0][2] = backAxis.x;
		result[1][2] = backAxis.y;
		result[2][2] = backAxis.z;

		result[3][0] = -rightAxis.x * eye.x - rightAxis.y * eye.y - rightAxis.z * eye.z;
		result[3][1] = -upAxis.x * eye.x - upAxis.y * eye.y - upAxis.z * eye.z;
		result[3][2] = -backAxis.x * eye.x - backAxis.y * eye.y - backAxis.z * eye.z;

		return result;

	}


	//http://stackoverflow.com/questions/13166135/how-does-glulookat-work
	Matrix4 lookAt2(Vector3 eye, Vector3 target, Vector3 up)
	{
		//we need three basis vector to get this. // right , up , backward(for right hand coordinate system)
		Matrix4 rotation;

		Vector3 backAxis = normalize(eye - target);
		Vector3 rightAxis = normalize(cross(up, backAxis));
		Vector3 upAxis = normalize(cross(backAxis, rightAxis));

		//This rotation matrix is only for zero translation transformation.  so first we need to negate the translation part by multplying it with negative translation,
		rotation[0][0] = rightAxis.x;
		rotation[1][0] = rightAxis.y;
		rotation[2][0] = rightAxis.z;

		rotation[0][1] = upAxis.x;
		rotation[1][1] = upAxis.y;
		rotation[2][1] = upAxis.z;

		rotation[0][2] = backAxis.x;
		rotation[1][2] = backAxis.y;
		rotation[2][2] = backAxis.z;

		Matrix4 translation;
		translation[3][0] = -eye.x;
		translation[3][1] = -eye.y;
		translation[3][2] = -eye.z;

		return rotation * translation;

	}

	Matrix4 prespectiveProjection()
	{
		Matrix4 result;
		return result;
	}

	Matrix4 orthographicProjection2D()
	{
		Matrix4 result;
		return result;
	}

	Matrix4 axisAngleRotation()
	{
		Matrix4 result;
		return result;
	}

}


