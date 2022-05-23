#pragma once

#include <cassert>
#include <cstdint>

template <typename T>
class Vector3 {
 public:
  T& operator[](std::uint64_t index);
  const T& operator[](std::uint64_t index) const;

  Vector3& operator+=(const Vector3& rhs);
  Vector3& operator-=(const Vector3& rhs);
  Vector3& operator*=(const T rhs);

 public:
  union {
    struct {
      T x;
      T y;
      T z;
    };
    struct {
      T r;
      T g;
      T b;
    };
    T components[3];
  };
};

template <typename T>
Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs);

template <typename T>
Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs);

template <typename T>
Vector3<T> operator*(const Vector3<T>& lhs, T rhs);

template <typename T>
T DotProduct(const Vector3<T>& lhs, const Vector3<T>& rhs);

////////////////////////////////////////////////////////////////////////////////

#include <math/vector3.ipp>

////////////////////////////////////////////////////////////////////////////////

typedef Vector3<std::int32_t>  Vector3i;
typedef Vector3<std::uint32_t> Vector3u;
typedef Vector3<float>         Vector3f;

float    Length   (const Vector3f& vector);
Vector3f Normilize(const Vector3f& vector);