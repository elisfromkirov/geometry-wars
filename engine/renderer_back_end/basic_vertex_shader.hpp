#pragma once

#include <math/vector3.hpp>

template <typename Vertex>
class BasicVertexShader {
 public:
  virtual ~BasicVertexShader() = default;

  virtual Vector3f Process(const Vertex& vertex) = 0;
};