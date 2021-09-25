#pragma once
#include "MathDefine.h"
#include "Vector.h"

TMATH_NAMESPACE

typedef Vector<float, 2> Vec2f;

constexpr Vector<float, 2> kVec2fZero = Vector<float, 2>(0.f);
constexpr Vector<float, 2> kVec2fOne = Vector<float, 2>(1.f);

END_NAMESPACE