template <typename T>
T& Vector3<T>::operator[](std::uint64_t index) {
  assert(index < 3);

  return components[index];
}

template <typename T>
const T& Vector3<T>::operator[](std::uint64_t index) const {
  assert(index < 3);

  return components[index];
}

template <typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3& rhs) {
  x += rhs.x;
  y += rhs.y;
  z += rhs.z;
  return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3& rhs) {
  x -= rhs.x;
  y -= rhs.y;
  z -= rhs.z;
  return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator*=(const T rhs) {
  x *= rhs;
  y *= rhs;
  z *= rhs;
  return *this;
}

template <typename T>
Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs) {
  Vector3<T> result{lhs};
  result += rhs;
  return result;
}

template <typename T>
Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs) {
  Vector3<T> result{lhs};
  result -= rhs;
  return result;
}

template <typename T>
Vector3<T> operator*(const Vector3<T>& lhs, T rhs) {
  Vector3<T> result{lhs};
  result *= rhs;
  return result;
}

template <typename T>
T DotProduct(const Vector3<T>& lhs, const Vector3<T>& rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}