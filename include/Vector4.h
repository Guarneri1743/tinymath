#pragma once
#include "MathDefine.h"
#include "Vector.h"

TMATH_NAMESPACE

typedef Vector<float, 4> Vec4f;

constexpr Vector<float, 4> kVec4fZero = Vector<float, 4>(0.f);
constexpr Vector<float, 4> kVec4fOne = Vector<float, 4>(1.f);

END_NAMESPACE