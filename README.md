# tinymath (WIP)
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

	// or

	#include "TinyMath.h" // you can simply include TinyMath.h instead of including each one of them for convenience



Alternatively, you can include "Vector.h" and "Matrix.h" to define your own type name

	#include "Vector.h"
	#include "Matrix.h"
	#include "Computation.h" 

	typedef Vector<uint32_t, 3> Vector3Uint;
	typedef Matrix<int, 4, 3> Matrix4x3Int;
	

# Examples

Vector arithmetic operations
	
	tinymath::vec4f v1(0.3f, -2.7f, 7.8f, 1.0f);
	tinymath::vec4f v2(3.8f, 7.4f, -20.3f, 3.0f);

	tinymath::vec4f add = v1 + v2;
	tinymath::vec4f mul = v1 * v2;
	tinymath::vec4f div = v1 / v2;
	tinymath::vec4f sub = v1 - v2;

Swizzling

	tinymath::vec4f add = v1.xyzw + v2.xxzy;
	tinymath::vec4f mul = v1.xwyz * v2.yyxw;

Matrix arithmetic operations
	
	tinymath::mat4x4 m1
	(
	1, -2, 3, 4,
	1, 3, 0, 1,
	1, -1, 2, 2,
	0, 0, 0, 1
	);
	
	tinymath::mat4x4 m2
	(
	1, -2, 3, 4,
	1, 3, 0, 1,
	1, -1, 2, 2,
	0, 0, 0, 1
	);

	tinymath::mat4x4 mul = m1 * m2;
	tinymath::mat4x4 add = m1 + m2;
	tinymath::mat4x4 sub = m1 - m2;

Determinant

	float det = tinymath::determinant(m1)

Transpose

	tinymath::mat4x4 inversed_m1 = tinymath::inverse(m1);

Inverse

	tinymath::mat4x4 transposed_m1 = tinymath::transpose(m1);
	
Translation

	tinymath::mat4x4 t = tinymath::translation(tinymath::vec3f(1.f, 2.f, 3.f));
	tinymath::vec3f point = tinymath::vec3f(3.f, 4.f, 5.f);
	tinymath::vec3f translated_pt = tinymath::transform_point(t, point);

Rotation
	
	tinymath::mat4x4 r = tinymath::rotation(Vec3f(0.f, 1.f, 0.f), 90.f);
	tinymath::vec3f point = tinymath::vec3f(3.f, 4.f, 5.f);
	tinymath::vec3f rotated_pt = tinymath::transform_point(r, point);

Scaling

	tinymath::mat4x4 s = tinymath::vec3fscale(Vec3f(2.f, 3.f, 4.f));
	tinymath::vec3f point = tinymath::vec3f(3.f, 4.f, 5.f);
	tinymath::vec3f scaled_pt = tinymath::vec3ftransform_point(s, point);

Combined Transformation

	tinymath::mat4x4 t = tinymath::translation(tinymath::vec3f(1.f, 2.f, 3.f));
	tinymath::mat4x4 r = tinymath::rotation(tinymath::vec3f(0.f, 1.f, 0.f), 90.f);
	tinymath::mat4x4 s = tinymath::scale(tinymath::vec3f(2.f, 3.f, 4.f));
	tinymath::mat4x4 trs = t * r * s;

	tinymath::vec3f point = tinymath::vec3f(3.f, 4.f, 5.f);

	tinymath::vec3f transformed_pt = tinymath::transform_point(trs, point);
	

Perspective projection matrix

	tinymath::mat4x4 perspective_proj = tinymath::perspective(60.0f, 60.0f, 0.0f, 100.0f);

Ortho projection matrix

	tinymath::mat4x4 ortho_proj = tinymath::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);

Lookat matrix

	tinymath::mat4x4 lookat_mat = tinymath::lookat(tinymath::vec3f(10.0f), tinymath::vec3f(0.0f), tinymath::vec3fkVec3fUp);

# TODO

- Quaternion



