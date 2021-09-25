TMATH_NAMESPACE

#define rc2index(row, col, COL) row * COL + col

// suppress c4201
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4201)
#endif
template <typename Component>
struct Matrix<Component, 3, 3>
{
	union
	{
		Component data[9];
		struct
		{
			Component m00;
			Component m01;
			Component m02;
			Component m10;
			Component m11;
			Component m12;
			Component m20;
			Component m21;
			Component m22;
		};
	};

	Matrix<Component, 3, 3>() {}

	constexpr Matrix<Component, 3, 3>(const Component& v) :
		m00(v), m01(v), m02(v),
		m10(v), m11(v), m12(v),
		m20(v), m21(v), m22(v)
	{}

	constexpr Matrix<Component, 3, 3>(const Vector<Component, 3>& row0, const Vector<Component, 3>& row1, const Vector<Component, 3>& row2) :
		m00(row0.x), m01(row0.y), m02(row0.z),
		m10(row1.x), m11(row1.y), m12(row1.z),
		m20(row2.x), m21(row2.y), m22(row2.z)
	{}

	constexpr Matrix<Component, 3, 3>(const float& _m00, const float& _m01, const float& _m02,
									  const float& _m10, const float& _m11, const float& _m12,
									  const float& _m20, const float& _m21, const float& _m22) :
		m00(_m00), m01(_m01), m02(_m02),
		m10(_m10), m11(_m11), m12(_m12),
		m20(_m20), m21(_m21), m22(_m22)
	{}

	constexpr Matrix<Component, 3, 3>(const Matrix<Component, 3, 3>& m) :
		m00(m.m00), m01(m.m01), m02(m.m02),
		m10(m.m10), m11(m.m11), m12(m.m12),
		m20(m.m20), m21(m.m21), m22(m.m22)
	{}

	Component& operator[](const size_t& index) { return data[index]; }
	const Component& operator[](const size_t& index) const { return data[index]; }

	Component& at(const size_t& r, const size_t& c) { return data[rc2index(r, c, 3)]; }
	const Component& at(const size_t& r, const size_t& c) const { return data[rc2index(r, c, 3)]; }
};

template <typename Component>
struct Matrix<Component, 4, 4>
{
	union
	{
		Component data[16];
		struct
		{
			Component m00;
			Component m01;
			Component m02;
			Component m03;
			Component m10;
			Component m11;
			Component m12;
			Component m13;
			Component m20;
			Component m21;
			Component m22;
			Component m23;
			Component m30;
			Component m31;
			Component m32;
			Component m33;
		};
	};

	Matrix<Component, 4, 4>() {}

	constexpr Matrix<Component, 4, 4>(const Component& v) :
		m00(v), m01(v), m02(v), m03(v),
		m10(v), m11(v), m12(v), m13(v),
		m20(v), m21(v), m22(v), m23(v),
		m30(v), m31(v), m32(v), m33(v)
	{}

	constexpr Matrix<Component, 4, 4>(const Vector<Component, 4>& row0, const Vector<Component, 4>& row1, const Vector<Component, 4>& row2, const Vector<Component, 4>& row3) :
		m00(row0.x), m01(row0.y), m02(row0.z), m03(row0.w),
		m10(row1.x), m11(row1.y), m12(row1.z), m13(row1.w),
		m20(row2.x), m21(row2.y), m22(row2.z), m23(row2.w),
		m30(row3.x), m31(row3.y), m32(row3.z), m33(row3.w)
	{}

	constexpr Matrix<Component, 4, 4>(const float& _m00, const float& _m01, const float& _m02, const float& _m03,
									  const float& _m10, const float& _m11, const float& _m12, const float& _m13,
									  const float& _m20, const float& _m21, const float& _m22, const float& _m23,
									  const float& _m30, const float& _m31, const float& _m32, const float& _m33) :
		m00(_m00), m01(_m01), m02(_m02), m03(_m03),
		m10(_m10), m11(_m11), m12(_m12), m13(_m13),
		m20(_m20), m21(_m21), m22(_m22), m23(_m23),
		m30(_m30), m31(_m31), m32(_m32), m33(_m33)
	{}

	constexpr Matrix<Component, 4, 4>(const Matrix<Component, 4, 4>& m) :
		m00(m.m00), m01(m.m01), m02(m.m02), m03(m.m03),
		m10(m.m10), m11(m.m11), m12(m.m12), m13(m.m13),
		m20(m.m20), m21(m.m21), m22(m.m22), m23(m.m23),
		m30(m.m30), m31(m.m31), m32(m.m32), m33(m.m33)
	{}

	Component& operator[](const size_t& index) { return data[index]; }
	const Component& operator[](const size_t& index) const { return data[index]; }

	Component& at(const size_t& r, const size_t& c) { return data[rc2index(r, c, 4)]; }
	const Component& at(const size_t& r, const size_t& c) const { return data[rc2index(r, c, 4)]; }
};
#if defined(_MSC_VER)
#pragma warning(pop)
#endif

template<typename Component, size_t ROW, size_t COL>
bool operator!=(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs)
{
	for (size_t idx = 0; idx < ROW * COL; ++idx) { if (lhs[idx] != rhs[idx]) return true; } return false;
}

template<typename Component, size_t ROW, size_t COL>
bool operator==(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs)
{
	for (size_t idx = 0; idx < ROW * COL; ++idx) { if (lhs[idx] != rhs[idx]) return false; } return true;
}

template<typename Component, size_t ROW, size_t COL>
Matrix<Component, ROW, COL> operator-(const Matrix<Component, ROW, COL>& v)
{
	Matrix<Component, ROW, COL> ret = Matrix<Component, ROW, COL>();

	for (size_t r = 0; r < ROW; ++r)
	{
		for (size_t c = 0; c < COL; ++c)
		{
			ret.at(r, c) = -v.at(r, c);
		}
	}

	return ret;
}

template<typename Component, size_t ROW, size_t COL>
Matrix<Component, ROW, COL> operator+(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs)
{
	Matrix<Component, ROW, COL> ret = Matrix<Component, ROW, COL>();

	for (size_t r = 0; r < ROW; ++r)
	{
		for (size_t c = 0; c < COL; ++c)
		{
			ret.at(r, c) = lhs.at(r, c) + rhs.at(r, c);
		}
	}

	return ret;
}

template<typename Component, size_t ROW, size_t COL>
Matrix<Component, ROW, COL> operator-(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs)
{
	Matrix<Component, ROW, COL> ret = Matrix<Component, ROW, COL>();

	for (size_t r = 0; r < ROW; ++r)
	{
		for (size_t c = 0; c < COL; ++c)
		{
			ret.at(r, c) = lhs.at(r, c) - rhs.at(r, c);
		}
	}

	return ret;
}

template<typename Component, size_t ROW, size_t N, size_t COL>
Matrix<Component, ROW, COL> operator*(const Matrix<Component, ROW, N>& lhs, const Matrix<Component, N, COL>& rhs)
{
	Matrix<Component, ROW, COL> ret = Matrix<Component, ROW, COL>();

	for (size_t r = 0; r < ROW; ++r)
	{
		Component row[N];
		for (size_t c0 = 0; c0 < N; ++c0)
		{
			row[c0] = lhs.at(r, c0);
		}

		for (size_t c = 0; c < COL; ++c)
		{
			Component col[N];
			for (size_t r1 = 0; r1 < N; ++r1)
			{
				col[r1] = rhs.at(r1, c);
			}

			ret.at(r, c) = Component();
			for (size_t idx = 0; idx < N; idx++)
			{
				ret.at(r, c) += row[idx] * col[idx];
			}
		}
	}

	return ret;
}

template<typename Component>
Component determinant(const Matrix<Component, 3, 3>& m)
{
	return  m.at(0, 0) * (m.at(1, 1) * m.at(2, 2) - m.at(1, 2) * m.at(2, 1)) -
		m.at(0, 1) * (m.at(1, 2) * m.at(2, 0) - m.at(1, 0) * m.at(2, 2)) +
		m.at(0, 2) * (m.at(1, 0) * m.at(2, 1) - m.at(1, 1) * m.at(2, 0));
}

template<typename Component>
Component determinant(const Matrix<Component, 4, 4>& m)
{
	Component m00 = m.at(0, 0);
	Component m10 = m.at(1, 0);
	Component m20 = m.at(2, 0);
	Component m30 = m.at(3, 0);
	Component m01 = m.at(0, 1);
	Component m11 = m.at(1, 1);
	Component m21 = m.at(2, 1);
	Component m31 = m.at(3, 1);
	Component m02 = m.at(0, 2);
	Component m12 = m.at(1, 2);
	Component m22 = m.at(2, 2);
	Component m32 = m.at(3, 2);
	Component m03 = m.at(0, 3);
	Component m13 = m.at(1, 3);
	Component m23 = m.at(2, 3);
	Component m33 = m.at(3, 3);

	return  m03 * m12 * m21 * m30 - m02 * m13 * m21 * m30 - m03 * m11 * m22 * m30 + m01 * m13 * m22 * m30 +
		m02 * m11 * m23 * m30 - m01 * m12 * m23 * m30 - m03 * m12 * m20 * m31 + m02 * m13 * m20 * m31 +
		m03 * m10 * m22 * m31 - m00 * m13 * m22 * m31 - m02 * m10 * m23 * m31 + m00 * m12 * m23 * m31 +
		m03 * m11 * m20 * m32 - m01 * m13 * m20 * m32 - m03 * m10 * m21 * m32 + m00 * m13 * m21 * m32 +
		m01 * m10 * m23 * m32 - m00 * m11 * m23 * m32 - m02 * m11 * m20 * m33 + m01 * m12 * m20 * m33 +
		m02 * m10 * m21 * m33 - m00 * m12 * m21 * m33 - m01 * m10 * m22 * m33 + m00 * m11 * m22 * m33;
}

template<typename Component>
Matrix<Component, 3, 3> inverse(const Matrix<Component, 3, 3>& m)
{
	Component one_over_det = (Component)1 / determinant(m);
	Matrix<Component, 3, 3> ret = Matrix<float, 3, 3>(1, 0, 0, 
													  0, 1, 0, 
													  0, 0, 1);

	ret[0] = (m[5] * m[10] - m[6] * m[9]) * one_over_det;
	ret[1] = -(m[1] * m[10] - m[2] * m[9]) * one_over_det;
	ret[2] = (m[1] * m[6] - m[2] * m[5]) * one_over_det;
	ret[4] = -(m[4] * m[10] - m[6] * m[8]) * one_over_det;
	ret[5] = (m[0] * m[10] - m[2] * m[8]) * one_over_det;
	ret[6] = -(m[0] * m[6] - m[2] * m[4]) * one_over_det;
	ret[8] = (m[4] * m[9] - m[5] * m[8]) * one_over_det;
	ret[9] = -(m[0] * m[9] - m[1] * m[8]) * one_over_det;
	ret[10] = (m[0] * m[5] - m[1] * m[4]) * one_over_det;
	return ret;
}

template<typename Component>
Matrix<Component, 4, 4> inverse(const Matrix<Component, 4, 4>& m)
{
	Component s0 = ((m[0] * m[5]) - (m[1] * m[4]));
	Component s1 = ((m[0] * m[6]) - (m[2] * m[4]));
	Component s2 = ((m[0] * m[7]) - (m[3] * m[4]));
	Component s3 = ((m[1] * m[6]) - (m[2] * m[5]));
	Component s4 = ((m[1] * m[7]) - (m[3] * m[5]));
	Component s5 = ((m[2] * m[7]) - (m[3] * m[6]));

	Component c5 = ((m[10] * m[15]) - (m[11] * m[14]));
	Component c4 = ((m[9] * m[15]) - (m[11] * m[13]));
	Component c3 = ((m[9] * m[14]) - (m[10] * m[13]));
	Component c2 = ((m[8] * m[15]) - (m[11] * m[12]));
	Component c1 = ((m[8] * m[14]) - (m[10] * m[12]));
	Component c0 = ((m[8] * m[13]) - (m[9] * m[12]));

	Component det = (s0 * c5) - (s1 * c4) + (s2 * c3) + (s3 * c2) - (s4 * c1) + (s5 * c0);

	Component one_over_det = (Component)1 / det;
	Matrix<Component, 4, 4> ret = Matrix<float, 4, 4>(1, 0, 0, 0, 
													  0, 1, 0, 0, 
													  0, 0, 1, 0, 
													  0, 0, 0, 1);

	ret[0] = +(m[5] * c5 - m[6] * c4 + m[7] * c3) * one_over_det;
	ret[1] = -(m[1] * c5 - m[2] * c4 + m[3] * c3) * one_over_det;
	ret[2] = +(m[13] * s5 - m[14] * s4 + m[15] * s3) * one_over_det;
	ret[3] = -(m[9] * s5 - m[10] * s4 + m[11] * s3) * one_over_det;
	ret[4] = -(m[4] * c5 - m[6] * c2 + m[7] * c1) * one_over_det;
	ret[5] = +(m[0] * c5 - m[2] * c2 + m[3] * c1) * one_over_det;
	ret[6] = -(m[12] * s5 - m[14] * s2 + m[15] * s1) * one_over_det;
	ret[7] = +(m[8] * s5 - m[10] * s2 + m[11] * s1) * one_over_det;
	ret[8] = +(m[4] * c4 - m[5] * c2 + m[7] * c0) * one_over_det;
	ret[9] = -(m[0] * c4 - m[1] * c2 + m[3] * c0) * one_over_det;
	ret[10] = +(m[12] * s4 - m[13] * s2 + m[15] * s0) * one_over_det;
	ret[11] = -(m[8] * s4 - m[9] * s2 + m[11] * s0) * one_over_det;
	ret[12] = -(m[4] * c3 - m[5] * c1 + m[6] * c0) * one_over_det;
	ret[13] = +(m[0] * c3 - m[1] * c1 + m[2] * c0) * one_over_det;
	ret[14] = -(m[12] * s3 - m[13] * s1 + m[14] * s0) * one_over_det;
	ret[15] = +(m[8] * s3 - m[9] * s1 + m[10] * s0) * one_over_det;

	return ret;
}

template<typename Component, size_t ROW, size_t COL>
Matrix<Component, ROW, COL> transpose(const Matrix<Component, ROW, COL>& m)
{
	Matrix<Component, ROW, COL> ret = Matrix<Component, ROW, COL>();

	for (size_t r = 0; r < ROW; ++r)
	{
		for (size_t c = 0; c < COL; ++c)
		{
			ret.at(c, r) = m.at(r, c);
		}
	}

	return ret;
}

template<typename Component, size_t ROW, size_t COL>
TMATH_INLINE bool approx(const Matrix<Component, ROW, COL>& lhs, const Matrix<Component, ROW, COL>& rhs)
{
	for (size_t idx = 0; idx < ROW * COL; ++idx) { if (abs(lhs[idx] - rhs[idx]) > EPSILON) return false; } return true;
}

END_NAMESPACE