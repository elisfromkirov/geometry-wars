#include <math/vector3.hpp>

#include <cmath>
#include <cfloat>

float Length(const Vector3f& vector) {
  return std::sqrt(DotProduct(vector, vector));
}

Vector3f Normilize(const Vector3f& vector) {
  float length{Length(vector)};
  
  if (std::fabs(length) < FLT_EPSILON) {
    return vector;
  }

  return vector * (1.f / length);
}