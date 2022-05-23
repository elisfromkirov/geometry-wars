#pragma once

#include <cassert>
#include <cstdint>

template <typename T>
class Vector2 {
 public:
  T& operator[](std::uint64_t index);
  const T& operator[](std::uint64_t index) const;

  Vector2& operator+=(const Vector2& rhs);
  Vector2& operator-=(const Vector2& rhs);
  Vector2& operator*=(const T rhs);

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
Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs);

template <typename T>
Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs);

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, T rhs);

template <typename T>
T DotProduct(const Vector2<T>& lhs, const Vector2<T>& rhs);

////////////////////////////////////////////////////////////////////////////////

#include <math/vector2.ipp>

////////////////////////////////////////////////////////////////////////////////

typedef Vector2<std::int32_t>  Vector2i;
typedef Vector2<std::uint32_t> Vector2u;
typedef Vector2<float>         Vector2f;

float    Length   (const Vector2f& vector);
Vector2f Normilize(const Vector2f& vector);