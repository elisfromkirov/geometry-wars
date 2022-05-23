#pragma once

#include <math/vector3.hpp>

#include <cassert>
#include <cstddef>

template <typename T>
class Matrix3x3 {
 public:
  Vector3<T>& operator[](std::uint64_t index);
  const Vector3<T>& operator[](std::uint64_t index) const;

  Matrix3x3& operator+=(const Matrix3x3& rhs);
  Matrix3x3& operator-=(const Matrix3x3& rhs);
  Matrix3x3& operator*=(const Matrix3x3& rhs);
  Matrix3x3& operator*=(T rhs);

 public:
  Vector3<T> columns[3];
};

template <typename T>
Matrix3x3<T> operator+(const Matrix3x3<T>& lhs, const Matrix3x3<T>& rhs);

template <typename T>
Matrix3x3<T> operator-(const Matrix3x3<T>& lhs, const Matrix3x3<T>& rhs);

template <typename T>
Matrix3x3<T> operator*(const Matrix3x3<T>& lhs, const Matrix3x3<T>& rhs);

template <typename T>
Matrix3x3<T> operator*(const Matrix3x3<T>& lhs, T rhs);

template <typename T>
Vector3<T> operator*(const Matrix3x3<T>& lhs, const Vector3<T>& rhs);

template <typename T>
Matrix3x3<T> Transponse(const Matrix3x3<T>& matrix);

////////////////////////////////////////////////////////////////////////////////

#include <math/matrix3x3.ipp>

////////////////////////////////////////////////////////////////////////////////

typedef Matrix3x3<float> Matrix3x3f;