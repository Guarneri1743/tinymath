# TinyMath
 A small math library written in C++14


# Usage

Only one header need to be inclueded

	#include "TinyMath.h"
	using namespace TMath;

Vector operations
	
	Vec4f v1(0.3f, -2.7f, 7.8f, 1.0f);
	Vec4f v2(3.8f, 7.4f, -20.3f, 3.0f);
	Vec4f add = v1 + v2;
	Vec4f mul = v1 * v2;
	Vec4f div = v1 / v2;
	Vec4f sub = v1 - v2;

Swizzling

	Vec4f add = v1.xyzw + v2.xxzy;
	Vec4f mul = v1.xwyz * v2.yyxw;

Matrix operations
	
	Matrix4x4 m1(1, -2, 3, 4,
				 1, 3, 0, 1,
				 1, -1, 2, 2,
				 0, 0, 0, 1);
	
	Matrix4x4 m2(1, -2, 3, 4,
				 1, 3, 0, 1,
				 1, -1, 2, 2,
				 0, 0, 0, 1);

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

	Matrix4x4 translation = Matrix4x4(1, 0, 0, 1.5,
									  0, 1, 0, 2.7,
									  0, 0, 1, 3,
									  0, 0, 0, 1);
	
	Vec4f vec = Vec4f(0.2f, 7.5f, 123.f, 1.0f);
	auto translated = translation * vec;
	
Rotation
	
	float rad = DEGREE2RAD(90);
	Matrix4x4 rotation = Matrix4x4(TMath::cos(rad), 0, -TMath::sin(rad), 0,
								   0, 1, 0, 0,
								   TMath::sin(rad), 0, TMath::cos(rad), 0,
								   0, 0, 0, 1);
	
	Vec4f vec = Vec4f(1.0f, 1.0f, 1.0f, 1.0f);
	auto rotated = rotation * vec;

	
Scaling

	Matrix4x4 scale = Matrix4x4(2, 0, 0, 0,
								0, 3, 0, 0,
								0, 0, 4, 0,
								0, 0, 0, 1);
	
	Vec4f vec = Vec4f(1.0f, 1.0f, 1.0f, 1.0f);
	auto scaled = scale * vec;