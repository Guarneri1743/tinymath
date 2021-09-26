# TinyMath (WIP)
 A small math library written in C++14 

# Install
run 'setup.bat'

# Usage

First of all, include the headers you want to use

	#include "Vector2.h"
	#include "Vector3.h"
	#include "Vector4.h"
	#include "Vector2Int.h"
	#include "Vector3Int.h"
	#include "Vector4Int.h"
	#include "Matrix3x3.h"
	#include "Matrix4x4.h"
	#include "Computation.h"

	using namespace TMath;

	// or

	#include "TinyMath.h" // you can simply include TinyMath.h instead of including each one of them for convenience

	using namespace TMath;



Alternatively, you can include "Vector.h" and "Matrix.h" to define your own type name

	#include "Vector.h"
	#include "Matrix.h"
	#include "Computation.h" 

	typedef Vector<uint32_t, 3> Vector3Uint;
	typedef Matrix<int, 4, 3> Matrix4x3Int;
	

# Examples

Vector arithmetic operations
	
	Vec4f v1(0.3f, -2.7f, 7.8f, 1.0f);
	Vec4f v2(3.8f, 7.4f, -20.3f, 3.0f);
	Vec4f add = v1 + v2;
	Vec4f mul = v1 * v2;
	Vec4f div = v1 / v2;
	Vec4f sub = v1 - v2;

Swizzling

	Vec4f add = v1.xyzw + v2.xxzy;
	Vec4f mul = v1.xwyz * v2.yyxw;

Matrix arithmetic operations
	
	Matrix4x4 m1
	(
	1, -2, 3, 4,
	1, 3, 0, 1,
	1, -1, 2, 2,
	0, 0, 0, 1
	);
	
	Matrix4x4 m2
	(
	1, -2, 3, 4,
	1, 3, 0, 1,
	1, -1, 2, 2,
	0, 0, 0, 1
	);

	Matrix4x4 mul = m1 * m2;
	Matrix4x4 add = m1 + m2;
	Matrix4x4 sub = m1 - m2;

Determinant

	float det = determinant(m1)

Transpose

	Matrix4x4 inversed_m1 = inverse(m1);

Inverse

	Matrix4x4 transposed_m1 = transpose(m1);
	
Translation

	Matrix4x4 t = translation(Vec3f(1.f, 2.f, 3.f));
	Vec3f point = Vec3f(3.f, 4.f, 5.f);
	Vec3f translated_pt = transform_point(t, point);

Rotation
	
	Matrix4x4 r = rotation(Vec3f(0.f, 1.f, 0.f), 90.f);
	Vec3f point = Vec3f(3.f, 4.f, 5.f);
	Vec3f rotated_pt = transform_point(r, point);

Scaling

	Matrix4x4 s = scale(Vec3f(2.f, 3.f, 4.f));
	Vec3f point = Vec3f(3.f, 4.f, 5.f);
	Vec3f scaled_pt = transform_point(s, point);

Combined Transformation

	Matrix4x4 t = translation(Vec3f(1.f, 2.f, 3.f));
	Matrix4x4 r = rotation(Vec3f(0.f, 1.f, 0.f), 90.f);
	Matrix4x4 s = scale(Vec3f(2.f, 3.f, 4.f));
	Matrix4x4 trs = t * r * s;

	Vec3f point = Vec3f(3.f, 4.f, 5.f);

	Vec3f transformed_pt = transform_point(trs, point);
	

Perspective projection matrix

	Matrix4x4 projection_mat = perspective(60.0f, 60.0f, 0.0f, 100.0f);

Ortho projection matrix

	Matrix4x4 ortho_mat = ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);

Lookat matrix

	Matrix4x4 lookat_mat = lookat(Vec3f(10.0f), Vec3f(0.0f), kVec3fUp);

# TODO

- Quaternion
- Lerp functions



