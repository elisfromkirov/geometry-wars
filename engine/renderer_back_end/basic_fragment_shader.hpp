#pragma once

#include <math/vector2.hpp>
#include <math/vector3.hpp>

template <typename Vertex>
class BasicFragmentShader {
 public:
  virtual ~BasicFragmentShader() = default;

  virtual Vector3f Process(Vector2i fragment) = 0;
};