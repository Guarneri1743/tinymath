#pragma once
#include "MathDefine.h"
#include "Matrix.h"

TMATH_NAMESPACE

typedef Matrix<float, 4, 4> Matrix4x4;

constexpr Matrix<float, 4, 4> kMat4x4Identity = Matrix<float, 4, 4>(1.f, 0.f, 0.f, 0.f,
																	0.f, 1.f, 0.f, 0.f,
																	0.f, 0.f, 1.f, 0.f,
																	0.f, 0.f, 0.f, 1.f);

END_NAMESPACE