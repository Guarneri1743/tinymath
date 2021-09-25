#pragma once
#include "MathDefine.h"
#include "Vector.h"

TMATH_NAMESPACE

template <typename Component, size_t ROW, size_t COL> struct Matrix;

template<typename Component, size_t ROW, size_t COL>
TMATH_INLINE bool operator!=(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs);

template<typename Component, size_t ROW, size_t COL>
TMATH_INLINE bool operator==(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs);

template<typename Component, size_t ROW, size_t COL>
TMATH_INLINE Matrix<Component, ROW, COL> operator-(const Matrix<Component, ROW, COL>& v);

template<typename Component, size_t ROW, size_t COL>
TMATH_INLINE Matrix<Component, ROW, COL> operator+(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs);

template<typename Component, size_t ROW, size_t COL>
TMATH_INLINE Matrix<Component, ROW, COL> operator-(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs);

template<typename Component, size_t ROW, size_t N, size_t COL>
TMATH_INLINE Matrix<Component, ROW, COL> operator*(const Matrix<Component, ROW, N>& lhs, const Matrix<Component, N, COL>& rhs);

template <typename Component> struct Matrix<Component, 3, 3>;
template <typename Component> struct Matrix<Component, 4, 4>;

template<typename Component>
TMATH_INLINE Component determinant(const Matrix<Component, 3, 3>& m);

template<typename Component>
TMATH_INLINE Component determinant(const Matrix<Component, 4, 4>& m);

template<typename Component>
TMATH_INLINE Matrix<Component, 3, 3> inverse(const Matrix<Component, 3, 3>& m);

template<typename Component>
TMATH_INLINE Matrix<Component, 4, 4> inverse(const Matrix<Component, 4, 4>& m);

template<typename Component, size_t ROW, size_t COL>
TMATH_INLINE Matrix<Component, ROW, COL> transpose(const Matrix<Component, ROW, COL>& m);

template<typename Component, size_t ROW, size_t COL>
TMATH_INLINE bool approx(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs);

END_NAMESPACE

#include "Matrix.inl"