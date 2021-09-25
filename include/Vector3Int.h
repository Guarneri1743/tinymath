#pragma once
#include "MathDefine.h"
#include "Vector.h"

TMATH_NAMESPACE

typedef Vector<int, 3> Vec3i;

constexpr Vector<int, 3> kVec3iZero = Vector<int, 3>(0);
constexpr Vector<int, 3> kVec3iOne = Vector<int, 3>(1);
constexpr Vector<int, 3> kVec3iUp = Vector<int, 3>(0, 1, 0);
constexpr Vector<int, 3> kVec3iDown = Vector<int, 3>(0, -1, 0);
constexpr Vector<int, 3> kVec3iLeft = Vector<int, 3>(-1, 0, 0);
constexpr Vector<int, 3> kVec3iRight = Vector<int, 3>(1, 0, 0);
constexpr Vector<int, 3> kVec3iForward = Vector<int, 3>(0, 0, 1);
constexpr Vector<int, 3> kVec3iBack = Vector<int, 3>(0, 0, -1);

END_NAMESPACE