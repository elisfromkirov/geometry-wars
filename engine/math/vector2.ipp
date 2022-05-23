template <typename T>
T& Vector2<T>::operator[](std::uint64_t index) {
  assert(index < 2);

  return components[index];
}

template <typename T>
const T& Vector2<T>::operator[](std::uint64_t index) const {
  assert(index < 2);

  return components[index];
}

template <typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2& rhs) {
  x += rhs.x;
  y += rhs.y;
  return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2& rhs) {
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=(const T rhs) {
  x *= rhs;
  y *= rhs;
  return *this;
}

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs) {
  Vector2<T> result{lhs};
  result += rhs;
  return result;
}

template <typename T>
Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs) {
  Vector2<T> result{lhs};
  result -= rhs;
  return result;
}

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, T rhs) {
  Vector2<T> result{lhs};
  result *= rhs;
  return result;
}

template <typename T>
T DotProduct(const Vector2<T>& lhs, const Vector2<T>& rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}