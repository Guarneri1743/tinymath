#include <iostream>
#include <assert.h>
#include "TinyMath.h"

#define TEST(label, block) \
			{\
			block \
			printf("TEST_CASE[%s]: %s\n", label, passed ? "PASSED" : "FAILED");\
			}

using namespace std;
using namespace tinymath;

int main()
{
	TEST(
		"Vector +-*/",
		vec4f v1(0.3f, -2.7f, 7.8f, 1.0f);
		vec4f v2(3.8f, 7.4f, -20.3f, 3.0f);
		vec4f add = v1 + v2;
		vec4f mul = v1 * v2;
		vec4f div = v1 / v2;
		vec4f sub = v1 - v2;
		bool add_pass = approx(add, vec4f(0.3f + 3.8f, -2.7f + 7.4f, 7.8f - 20.3f, 1.0f + 3.0f));
		bool sub_pass = approx(sub, vec4f(0.3f - 3.8f, -2.7f - 7.4f, 7.8f + 20.3f, 1.0f - 3.0f));
		bool mul_pass = approx(mul, vec4f(0.3f * 3.8f, -2.7f * 7.4f, 7.8f * -20.3f, 1.0f * 3.0f));
		bool div_pass = approx(div, vec4f(0.3f / 3.8f, -2.7f / 7.4f, 7.8f / -20.3f, 1.0f / 3.0f));
		bool passed = add_pass && sub_pass && mul_pass && div_pass;
	);

	TEST(
		"Vector ==/!=",
		vec4f v1(0.3333334f, -2.773378f, 7.8333333f, 1.0111f);
		vec4f v2(0.3333333f, -2.773377f, 7.8333334f, 1.0111f);
		vec4f v3(0.3333334f, -2.773378f, 7.8333333f, 1.0111f);
		bool flag1 = v1 != v2;
		bool flag2 = v1 == v3;
		bool flag3 = approx(v1, v2);
		bool flag4 = approx(v2, v3);
		bool passed = flag1 && flag2 && flag3 && flag4;
	);

	TEST(
		"Matrix +-*",
		mat4x4 m1(1, -2, 3, 4,
					 1, 3, 0, 1,
					 1, -1, 2, 2,
					 0, 0, 0, 1);

		mat4x4 m2(1, -2, 3, 4,
					 1, 3, 0, 1,
					 1, -1, 2, 2,
					 0, 0, 0, 1);

		mat4x4 mul = m1 * m2;
		mat4x4 add = m1 + m2;
		mat4x4 sub = m1 - m2;

		mat4x4 mul_verify(
			2, -11, 9, 12,
			4, 7, 3, 8,
			2, -7, 7, 9,
			0, 0, 0, 1
		);

		mat4x4 add_verify(
			2, -4, 6, 8,
			2, 6, 0, 2,
			2, -2, 4, 4,
			0, 0, 0, 2
		);

		mat4x4 sub_verify(0);

		bool passed = mul == mul_verify && add == add_verify && sub == sub_verify;
	);

	TEST("Matrix Inverse",
		 mat4x4 m1(1, -2, 3, 4,
					  1, 3, 0, 1,
					  1, -1, 2, 2,
					  0, 0, 0, 1);

		mat4x4 m2 = inverse(m1);
		mat4x4 m3 = inverse(m2);
		bool passed = m1 == m3;
	);

	TEST(
		"Matrix Transpose",
		mat4x4 m1(1, -2, 3, 4,
					 1, 3, 0, 1,
					 1, -1, 2, 2,
					 0, 0, 0, 1);

		mat4x4 verify(1, 1, 1, 0,
						 -2, 3, -1, 0,
						 3, 0, 2, 0,
						 4, 1, 2, 1);

		bool passed = transpose(m1) == verify;
	);

	TEST(
		"Matrix ==/!=",
		mat4x4 m1(0.3333334f, -2.773378f, 7.8333333f, 1.0111f,
					 0.3333334f, -2.773378f, 7.8333333f, 1.0111f,
					 0.3333334f, -2.773378f, 7.8333333f, 1.0111f,
					 0.3333334f, -2.773378f, 7.8333333f, 1.0111f);

		mat4x4 m2(0.3333333f, -2.773377f, 7.8333334f, 1.0111f,
					 0.3333333f, -2.773377f, 7.8333334f, 1.0111f,
					 0.3333333f, -2.773377f, 7.8333334f, 1.0111f,
					 0.3333333f, -2.773377f, 7.8333334f, 1.0111f);

		mat4x4 m3(0.3333334f, -2.773378f, 7.8333333f, 1.0111f,
					 0.3333334f, -2.773378f, 7.8333333f, 1.0111f,
					 0.3333334f, -2.773378f, 7.8333333f, 1.0111f,
					 0.3333334f, -2.773378f, 7.8333333f, 1.0111f);

		bool flag1 = m1 != m2;
		bool flag2 = m1 == m3;
		bool flag3 = approx(m1, m2);
		bool flag4 = approx(m2, m3);
		bool passed = flag1 && flag2 && flag3 && flag4;
	);

	TEST(
		"Translation",
		mat4x4 translation = mat4x4(1, 0, 0, 1.5,
										  0, 1, 0, 2.7,
										  0, 0, 1, 3,
										  0, 0, 0, 1);

		vec4f vec = vec4f(0.2f, 7.5f, 123.f, 1.0f);
		auto v = translation * vec;
		bool passed = (approx(v, vec4f(0.2f + 1.5f, 7.5f + 2.7f, 3.0f + 123.f, 1.0f)));
	);

	TEST(
		"Rotation",
		float rad = DEGREE2RAD(90);
		mat4x4 rotation = mat4x4(tinymath::cos(rad), 0, -tinymath::sin(rad), 0,
									   0, 1, 0, 0,
									   tinymath::sin(rad), 0, tinymath::cos(rad), 0,
									   0, 0, 0, 1);

		vec4f vec = vec4f(1.0f, 1.0f, 1.0f, 1.0f);
		auto v = rotation * vec;
		bool passed = tinymath::approx(v, { -1.0f, 1.0f ,1.0f, 1.0f });
	);

	TEST(
		"Scale",
		mat4x4 scale = mat4x4(2, 0, 0, 0,
									0, 3, 0, 0,
									0, 0, 4, 0,
									0, 0, 0, 1);

		vec4f vec = vec4f(1.0f, 1.0f, 1.0f, 1.0f);
		auto v = scale * vec;
		bool passed = tinymath::approx(v, { 2.0f, 3.0f , 4.0f, 1.0f });
	);
	return 0;
}