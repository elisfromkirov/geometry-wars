#pragma once

#include <math/matrix3x3.hpp>
#include <math/vector3.hpp>

#include <renderer_back_end/basic_fragment_shader.hpp>
#include <renderer_back_end/basic_vertex_shader.hpp>

#include <renderer/vertex.hpp>

class VertexShader : public BasicVertexShader<Vertex> {
 public:
  VertexShader();

  Vector3f Process(const Vertex& vertex) override;

  void SetModelMatrix(const Matrix3x3f& model);

  void SetProjMatrix(const Matrix3x3f& proj);

 private:
  Matrix3x3f model_;
  Matrix3x3f proj_;
  Matrix3x3f result_;
};

class FragmentShader : public BasicFragmentShader<Vertex> {
 public:
  FragmentShader();

  Vector3f Process(Vector2i fragment) override;

  void SetColor(const Vector3f& color);

 private:
  Vector3f color_;
};