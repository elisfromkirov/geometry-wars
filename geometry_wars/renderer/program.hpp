#pragma once

#include <renderer/shaders.hpp>
#include <renderer/vertex.hpp>

class Program : public BasicProgram<Vertex> {
 public:
  void UpdateModelMatrix(const Matrix3x3f& matrix); 
};