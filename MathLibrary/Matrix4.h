#pragma once
#include <MathDefine.h>
#include <Vector4.h>
#include <Matrix3.h>
#include <math.h>
#include <array>

namespace math
{

	/*
	m[0][0] m[1][0] m[2][0] m[3][0]
	m[0][1] m[1][1] m[2][1] m[3][1] 
	m[0][2] m[1][2] m[2][2] m[3][2]
	m[0][3] m[1][3] m[2][3] m[3][3]
	//Column major matrix and this is how it can be accessed
	*/

	struct Matrix4
	{
		union
		{
			struct
			{
				Vector4 x, y, z , w;
			};

			Vector4 vectors[4];
		};

		
		Matrix4(const Matrix4& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			this->w = rhs.w;
		}

	

		explicit Matrix4() :
			x(1, 0, 0, 0),
			y(0, 1, 0, 0),
			z(0, 0, 1 ,0),
			w(0, 0, 0, 1)
		{
		}

		explicit Matrix4(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4) :
			x(v1),
			y(v2),
			z(v3),
			w(v4)
		{

		}
		explicit Matrix4(const Matrix3& source)
		{
			operator=(Matrix4());
			operator=(source);
		}

		//we need const as well as non cost operators.
		inline const Vector4& operator[](usize index) const { return vectors[index]; }
		inline Vector4& operator[](usize index) { return vectors[index]; }

		inline Matrix4& operator=(const Matrix4& rhs)
		{
			for (usize col = 0; col < 4; col++)
			{
				(*this)[col] = rhs[col];
			}

			return *this;
		}

		inline Matrix4& operator=(const Matrix3& rhs)
		{
			for (usize col = 0; col < 3; col++)
			{
				for (usize row = 0; row < 3; row++)
				{
					(*this)[col][row] = rhs[col][row];
				}
			}
			return *this;
		}


	};


	inline Matrix4 operator+(const Matrix4& lhs, const Matrix4& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			ret[col] = lhs[col] + rhs[col];
		}

		return ret;
	}


	inline Matrix4& operator+=(Matrix4& lhs, const Matrix4& rhs)
	{
		for (usize col = 0; col < 4; col++)
		{
			lhs[col] += rhs[col];
		}
		return lhs;
	}

	inline Matrix4 operator-(const Matrix4& lhs, const Matrix4& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			ret[col] = lhs[col] - rhs[col];
		}
		return ret;
	}

	inline Matrix4& operator-=(Matrix4& lhs, const Matrix4& rhs)
	{
		for (usize col = 0; col < 4; col++)
		{
			lhs[col] -= rhs[col];
		}
		return lhs;
	}

	inline Matrix4 operator*(const Matrix4& lhs, const f32& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			ret[col] = lhs[col] * rhs;
		}

		return ret;
	}

	inline Matrix4 operator*(const Matrix4& lhs, const Matrix4& rhs)
	{
		Matrix4 result;
		result[0] = lhs[0] * rhs[0][0] + lhs[1] * rhs[0][1] + lhs[2] * rhs[0][2] + lhs[3] * rhs[0][3];
		result[1] = lhs[0] * rhs[1][0] + lhs[1] * rhs[1][1] + lhs[2] * rhs[1][2] + lhs[3] * rhs[1][3];
		result[2] = lhs[0] * rhs[2][0] + lhs[1] * rhs[2][1] + lhs[2] * rhs[2][2] + lhs[3] * rhs[2][3];
		result[3] = lhs[0] * rhs[3][0] + lhs[1] * rhs[3][1] + lhs[2] * rhs[3][2] + lhs[3] * rhs[3][3];
		return result;
	}


	inline Vector4 const operator*(const Matrix4& lhs, const Vector4& rhs)
	{
		return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2] + lhs[3] * rhs[3];
	}

	inline Matrix4 operator/(const Matrix4& lhs, const f32& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			ret[col] = lhs[col] / rhs;
		}

		return ret;
	}

	inline Matrix4& operator/=(Matrix4& lhs, const f32& rhs)
	{
		Matrix4 ret;
		for (usize col = 0; col < 4; col++)
		{
			lhs[col] /= rhs;
		}

		return ret;
	}

	inline bool operator==(const Matrix4& lhs, const Matrix4& rhs)
	{
		for (usize col = 0; col < 4; col++)
		{
			if (lhs[col] != rhs[col])
			{
				return false;
			}
		}
		return true;
	}


	inline bool operator!=(const Matrix4& lhs, const Matrix4& rhs)
	{
		for (usize col = 0; col < 4; col++)
		{
			if (lhs[col] != rhs[col])
			{
				return true;
			}
		}
		return false;
	}


	inline Matrix4 transpose(const Matrix4& source)
	{
		Matrix4 result;
		for (usize col = 0; col < 4; col++)
		{
			for (usize row = 0; row < 4; row++)
				result[col][row] = source[row][col];
		}
		return result;
	}

	/**
			a , b , c ,d
			e , f , g , h
			i , j , k , l
			m , n , o , p

			a(f(kp-lo) - g(jp-ln) + h(jo-nk))
           -b(e(kp-lo) - g(ip-lm) + h(io-mk))
		   +c(e(jp-ln) - f(ip-lm) + h(in-jm))
		   -d(e(jo-nk) - f(io-mk) + g(in-jm))
	*/
	inline f32 determinant(const Matrix4& source)
	{
		const f32 kp_lo = source[2][2] * source[3][3] - source[3][2] * source[2][3];
		const f32 jp_ln = source[1][2] * source[3][3] - source[3][2] * source[1][3];
		const f32 jo_nk = source[1][2] * source[2][3] - source[1][3] * source[2][2];
		const f32 ip_lm = source[0][2] * source[3][3] - source[3][2] * source[0][3];
		const f32 io_mk = source[0][2] * source[2][3] - source[0][3] * source[2][2];
		const f32 in_jm = source[0][2] * source[1][3] - source[1][2] * source[0][3];

		const f32 c00 =  source[0][0] * (source[1][1] * kp_lo - source[2][1] * jp_ln + source[3][1] * jo_nk);
		const f32 c01 = -source[1][0] * (source[0][1] * kp_lo - source[2][1] * ip_lm + source[3][1] * io_mk);
		const f32 c02 =  source[2][0] * (source[0][1] * jp_ln - source[1][1] * ip_lm + source[3][1] * in_jm);
		const f32 c03 = -source[3][0] * (source[0][1] * jo_nk - source[1][1] * io_mk + source[2][1] * in_jm);
		return c00+c01+c02+c03;
	}

	/**
	a , b , c ,d
	e , f , g , h
	i , j , k , l
	m , n , o , p

	cofactor matrix

	 +[f(kp-lo) - g(jp-ln) + h(jo-nk)]    -[e(kp-lo) -g(ip-lm) +h(io-mk)]     +[e(jp-ln) - f(ip-lm)+ h(in-jm)]    -[e(jo-nk) - f(io-mk) + g(in-jm)]
	 -[b(kp-lo) - c(jp-ln) + d(jo-nk)]    +[a(kp-lo) -c(ip-lm) +d(io-mk)]     -[a(jp-ln) - b(ip-lm)+ d(in-jm)]    +[a(jo-nk) - b(io-mk) + c(in-jm)]
	 +[b(gp-ho) - c(fp-hn) + d(fo-gn)]    -[a(gp-ho) -c(ep-hm) +d(eo-gm)]     +[a(fp-hn) - b(ep-hm)+ d(en-fm)]    -[a(fo-gn) - b(eo-gm) + c(en-fm)]
	 -[b(gl-hk) - c(fl-hj) + d(fk-gj) ]   +[a(gl-hk) -c(el-hi) +d(ek-gi)]     -[a(fl-hj) - b(el-hi) +d(ej-fi)]    +[a(fk-gj) - b(ek-gi) + c(ej-fi)] 


	*/

	inline Matrix4 inverse(const Matrix4& source)
	{
		const f32 kp_lo = source[2][2] * source[3][3] - source[3][2] * source[2][3];
		const f32 jp_ln = source[1][2] * source[3][3] - source[3][2] * source[1][3];
		const f32 jo_nk = source[1][2] * source[2][3] - source[1][3] * source[2][2];

		const f32 ip_lm = source[0][2] * source[3][3] - source[3][2] * source[0][3];
		const f32 io_mk = source[0][2] * source[2][3] - source[0][3] * source[2][2];
		const f32 in_jm = source[0][2] * source[1][3] - source[1][2] * source[0][3];

		const f32 gp_ho = source[2][1] * source[3][3] - source[3][1] * source[2][3];
		const f32 fp_hn = source[1][1] * source[3][3] - source[3][1] * source[1][3];
		const f32 fo_gn = source[1][1] * source[2][3] - source[2][1] * source[1][3];

		const f32 ep_hm = source[0][1] * source[3][3] - source[3][1] * source[0][3];
		const f32 eo_gm = source[0][1] * source[2][3] - source[2][1] * source[0][3];
		const f32 en_fm = source[0][1] * source[1][3] - source[1][1] * source[0][3];

		const f32 gl_hk = source[2][1] * source[3][2] - source[3][1] * source[2][2];
		const f32 fl_hj = source[1][1] * source[3][2] - source[3][1] * source[1][2];
		const f32 fk_gj = source[1][1] * source[2][2] - source[2][1] * source[1][2];

		const f32 el_hi = source[0][1] * source[3][2] - source[3][1] * source[0][2];
		const f32 ek_gi = source[0][1] * source[2][2] - source[2][1] * source[0][2];
		const f32 ej_fi = source[0][1] * source[1][2] - source[1][1] * source[0][2];


		Matrix4 cofactorsTranspose;
		cofactorsTranspose[0][0] = (+(source[1][1] * kp_lo - source[2][1] * jp_ln + source[3][1] * jo_nk));
		cofactorsTranspose[1][0] = (-(source[1][0] * kp_lo - source[2][0] * jp_ln + source[3][0] * jo_nk));
		cofactorsTranspose[2][0] = (+(source[1][0] * gp_ho - source[2][0] * fp_hn + source[3][0] * fo_gn));
		cofactorsTranspose[3][0] = (-(source[1][0] * gl_hk - source[2][0] * fl_hj + source[3][0] * fk_gj));
		
		cofactorsTranspose[0][1] = (-(source[0][1] * kp_lo - source[2][1] * ip_lm + source[3][1] * io_mk));
		cofactorsTranspose[1][1] = (+(source[0][0] * kp_lo - source[2][0] * ip_lm + source[3][0] * io_mk));
		cofactorsTranspose[2][1] = (-(source[0][0] * gp_ho - source[2][0] * ep_hm + source[3][0] * eo_gm));
		cofactorsTranspose[3][1] = (+(source[0][0] * gl_hk - source[2][0] * el_hi + source[3][0] * ek_gi));

		cofactorsTranspose[0][2] = (+(source[0][1] * jp_ln - source[1][1] * ip_lm + source[3][1] * in_jm));
		cofactorsTranspose[1][2] = (-(source[0][0] * jp_ln - source[1][0] * ip_lm + source[3][0] * in_jm));
		cofactorsTranspose[2][2] = (+(source[0][0] * fp_hn - source[1][0] * ep_hm + source[3][0] * en_fm));
		cofactorsTranspose[3][2] = (-(source[0][0] * fl_hj - source[1][0] * el_hi + source[3][0] * ej_fi));
		
		cofactorsTranspose[0][3] = (-(source[0][1] * jo_nk - source[1][1] * io_mk + source[2][1] * in_jm));
		cofactorsTranspose[1][3] = (+(source[0][0] * jo_nk - source[1][0] * io_mk + source[2][0] * in_jm));
		cofactorsTranspose[2][3] = (-(source[0][0] * fo_gn - source[1][0] * eo_gm + source[2][0] * en_fm));
		cofactorsTranspose[3][3] = (+(source[0][0] * fk_gj - source[1][0] * ek_gi + source[2][0] * ej_fi));

		cofactorsTranspose /= determinant(source);

		return cofactorsTranspose;
	}

	inline std::ostream& operator<<(std::ostream &out, Matrix4& source)
	{
		out << " \n Matrix4(" << source.x << ", \n " <<
							source.y << ", \n" <<
							source.z << ", \n" <<
							source.w << ") \n";
		return out;
	}


	//https://www.youtube.com/watch?v=s9FhcvjM7Hk
	inline Matrix4 lookAt(Vector3 eye, Vector3 target, Vector3 up)
	{
		//we need three basis vector to get this. // right , up , backward(for right hand coordinate system)
		Matrix4 result;

		Vector3 backAxis = normalize(eye - target);
		Vector3 rightAxis = normalize(cross(up, backAxis));
		Vector3 upAxis = normalize(cross(backAxis, rightAxis));

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
	inline Matrix4 lookAt2(Vector3 eye, Vector3 target, Vector3 up)
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
	//http://www.songho.ca/opengl/gl_projectionmatrix.html
	/*
	*/

	inline Matrix4 perspective(f32 fovInDeg , f32 aspect, f32 zNear, f32 zFar)
	{
		Matrix4 result;
		f32 zRange = zNear - zFar;
		f32 tanHalfFOV = tan(degToRad(fovInDeg / 2));

		result[0][0] = 1/(aspect * tanHalfFOV);
		result[0][1] = 0.0f;
		result[0][2] = 0.0f;
		result[0][3] = 0.0f;

		result[1][0] = 0.0f;
		result[1][1] = 1 / tanHalfFOV;
		result[1][2] = 0.0f;
		result[1][3] = 0.0f;

		result[2][0] = 0.0f;
		result[2][1] = 0.0f;
		result[2][2] = -(zNear + zFar)/(zFar - zNear);
		result[2][3] = -1.0f;

		result[3][0] = 0.0f;
		result[3][1] = 0.0f;
		result[3][2] = 2 * zFar * zNear / (zRange);
		result[3][3] = 0.0f;
		return result;
	}

	inline Matrix4 orthographic(f32 left, f32 right, f32 bottom, f32 top)
	{
		Matrix4 result;
		result[0][0] = 2.0f / (right - left);
		result[1][1] = 2.0f / (top - bottom);
		result[2][2] = -1.0f;
		result[3][1] = -(right + left) / (right - left);
		result[3][1] = -(top + bottom) / (top - bottom);
		return result;
	}

	inline Matrix4 orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 zNear, f32 zFar)
	{
		Matrix4 result;

		result[0][0] = 2.0f / (right - left);
		result[1][1] = 2.0f / (top - bottom);
		result[2][2] = -2.0f / (zFar - zNear);
		result[3][0] = -(right + left) / (right - left);
		result[3][1] = -(top + bottom) / (top - bottom);
		result[3][2] = -(zFar + zNear) / (zFar - zNear);

		return result;
	}

}


