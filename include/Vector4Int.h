#pragma once
#include "MathDefine.h"
#include "Vector.h"

TMATH_NAMESPACE

typedef Vector<int, 4> Vec4i;

constexpr Vector<int, 4> kVec4iZero = Vector<int, 4>(0);
constexpr Vector<int, 4> kVec4iOne = Vector<int, 4>(1);

END_NAMESPACE