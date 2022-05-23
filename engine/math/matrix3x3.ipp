template <typename T>
Vector3<T>& Matrix3x3<T>::operator[](std::uint64_t index) {
  assert(index < 3);

  return columns[index];
}

template <typename T>
const Vector3<T>& Matrix3x3<T>::operator[](std::uint64_t index) const {
  assert(index < 3);

  return columns[index];
}

template <typename T>
Matrix3x3<T>& Matrix3x3<T>::operator+=(const Matrix3x3<T>& rhs) {
  columns[0] += rhs;
  columns[1] += rhs;
  columns[2] += rhs;
  columns[3] += rhs;
  return *this;
}

template <typename T>
Matrix3x3<T>& Matrix3x3<T>::operator-=(const Matrix3x3<T>& rhs) {
  columns[0] -= rhs;
  columns[1] -= rhs;
  columns[2] -= rhs;
  columns[3] -= rhs;
  return *this;
}

template <typename T>
Matrix3x3<T>& Matrix3x3<T>::operator*=(const Matrix3x3<T>& rhs) {
  Matrix3x3<T> transponse{Transponse(*this)};
  for (size_t i = 0; i < 3; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      columns[i][j] = DotProduct(transponse.columns[i], rhs.columns[j]);
    }
  }
  return *this;
}

template <typename T>
Matrix3x3<T>& Matrix3x3<T>::operator*=(T rhs) {
  columns[0] *= rhs;
  columns[1] *= rhs;
  columns[2] *= rhs;
  columns[3] *= rhs;
  return *this;
}

template <typename T>
Matrix3x3<T> operator+(const Matrix3x3<T>& lhs, const Matrix3x3<T>& rhs) {
  Matrix3x3<T> result{lhs};
  result += rhs;
  return result;
}

template <typename T>
Matrix3x3<T> operator-(const Matrix3x3<T>& lhs, const Matrix3x3<T>& rhs) {
  Matrix3x3<T> result{lhs};
  result -= rhs;
  return result;
}

template <typename T>
Matrix3x3<T> operator*(const Matrix3x3<T>& lhs, const Matrix3x3<T>& rhs) {
  Matrix3x3<T> result{lhs};
  result *= rhs;
  return result;
}

template <typename T>
Matrix3x3<T> operator*(const Matrix3x3<T>& lhs, T rhs) {
  Matrix3x3<T> result{lhs};
  result *= rhs;
  return result;
}

template <typename T>
Vector3<T> operator*(const Matrix3x3<T>& lhs, const Vector3<T>& rhs) {
  return Vector3<T>{
    lhs[0][0] * rhs[0] + lhs[1][0] * rhs[1] + lhs[2][0] * rhs[2],
    lhs[0][1] * rhs[0] + lhs[1][1] * rhs[1] + lhs[2][1] * rhs[2],
    lhs[0][2] * rhs[0] + lhs[1][2] * rhs[1] + lhs[2][2] * rhs[2]
  };
}

template <typename T>
Matrix3x3<T> Transponse(const Matrix3x3<T>& matrix) {
  return Matrix3x3<T>{
    Vector3<T>{matrix.columns[0][0], matrix.columns[1][0], matrix.columns[2][0]},
    Vector3<T>{matrix.columns[0][1], matrix.columns[1][1], matrix.columns[2][1]},
    Vector3<T>{matrix.columns[0][2], matrix.columns[1][2], matrix.columns[2][2]}
  };
}