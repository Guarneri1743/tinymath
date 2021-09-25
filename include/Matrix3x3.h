#pragma once
#include "MathDefine.h"
#include "Matrix.h"

TMATH_NAMESPACE

typedef Matrix<float, 3, 3> Matrix3x3;

constexpr Matrix<float, 3, 3> kMat3x3Identity = Matrix<float, 3, 3>(1.f, 0.f, 0.f,
																	0.f, 1.f, 0.f,
																	0.f, 0.f, 1.f);

END_NAMESPACE