#pragma once
#include "MathDefine.h"
#include "Vector.h"

TMATH_NAMESPACE

typedef Vector<float, 3> Vec3f;

constexpr Vector<float, 3> kVec3fZero = Vector<float, 3>(0.f);
constexpr Vector<float, 3> kVec3fOne = Vector<float, 3>(1.f);
constexpr Vector<float, 3> kVec3fUp = Vector<float, 3>(0.f, 1.f, 0.f);
constexpr Vector<float, 3> kVec3fDown = Vector<float, 3>(0.f, -1.f, 0.f);
constexpr Vector<float, 3> kVec3fLeft = Vector<float, 3>(-1.f, 0.f, 0.f);
constexpr Vector<float, 3> kVec3fRight = Vector<float, 3>(1.f, 0.f, 0.f);
constexpr Vector<float, 3> kVec3fForward = Vector<float, 3>(0.f, 0.f, 1.f);
constexpr Vector<float, 3> kVec3fBack = Vector<float, 3>(0.f, 0.f, -1.f);

END_NAMESPACE