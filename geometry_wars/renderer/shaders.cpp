#include <renderer/shaders.hpp>

VertexShader::VertexShader()
    : model_{Vector3f{1.f, 0.f, 0.f}, Vector3f{0.f, 1.f, 0.f}, Vector3f{0.f, 0.f, 1.f}},
      proj_{Vector3f{1.f, 0.f, 0.f}, Vector3f{0.f, 1.f, 0.f}, Vector3f{0.f, 0.f, 1.f}},
      result_{Vector3f{1.f, 0.f, 0.f}, Vector3f{0.f, 1.f, 0.f}, Vector3f{0.f, 0.f, 1.f}} {
}

Vector3f VertexShader::Process(const Vertex& vertex) {
  return result_ * vertex.data;
}

void VertexShader::SetModelMatrix(const Matrix3x3f& model) {
  model_ = model;

  result_ = proj_ * model_;
}

void VertexShader::SetProjMatrix(const Matrix3x3f& proj) {
  proj_ = proj;

  result_ = proj_ * model_;
}

FragmentShader::FragmentShader()
    : color_{0.f, 0.f, 0.f} {
}

Vector3f FragmentShader::Process(Vector2i fragment) {
  return color_;
}

void FragmentShader::SetColor(const Vector3f& color) {
  color_ = color;
}