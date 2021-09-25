#pragma once
#include "MathDefine.h"

TMATH_NAMESPACE

float sin(const float& rad);
float asin(const float& val);
float cos(const float& rad);
float acos(const float& val);
float tan(const float& rad);
float atan(const float& rad);
float atan2(const float& y, const float& x);
float cot(const float& rad);
float floor(const float& val);
float ceil(const float& val);
float exp(const float& val);
float exp2(const float& val);
float log(const float& val);
float log2(const float& val);
float log10(const float& val);
float pow(const float& val, const float& power);
float modf(const float& val, float* integer);
float trunc(const float& val);
float lerp(const float& lhs, const float& rhs, const float& t);
bool approx(const float& lhs, const float& rhs);

template<typename T>
T max(const T& lhs, const T& rhs);
template<typename T>
T min(const T& lhs, const T& rhs);
template<typename T>
T abs(const T& val);
float sqrt(const float& val);
template<typename T>
T clamp(const T& val, const T& min_val, const T& max_val);
template <typename T>
int sgn(T val);
template<typename T>
void swap(T& a, T& b);

END_NAMESPACE

#include "Wrapper.inl"