#include <math/vector2.hpp>

#include <cmath>
#include <cfloat>

float Length(const Vector2f& vector) {
  return std::sqrt(DotProduct(vector, vector));
}

Vector2f Normilize(const Vector2f& vector) {
  float length{Length(vector)};
  
  if (std::fabs(length) < FLT_EPSILON) {
    return vector;
  }

  return vector * (1.f / length);
}