#pragma once

#define TMATH_NAMESPACE namespace TMath {
#define END_NAMESPACE }

#ifdef WIN32
#undef min
#undef max
#endif

TMATH_NAMESPACE

#ifndef FORCE_INLINE
#define TMATH_INLINE inline
#else
#ifdef _MSC_VER
#define TMATH_INLINE __forceinline
#else
#define TMATH_INLINE inline __attribute__((always_inline))
#endif
#endif

#define DEGREE2RAD(degree) degree * 0.0174532925f
#define RAD2DEGREE(rad) rad * 57.2957795786f
#define PI 3.141592653f
#define TWO_PI 6.283185307f
#define HALF_PI 1.570796326f
#define RCP_PI 0.318309886f
#define EPSILON 1e-06f
#define ONE_MINUS_EPSILON 1 - EPSILON

END_NAMESPACE