#include <renderer/program.hpp>

void Program::UpdateModelMatrix(const Matrix3x3f& matrix) {
  VertexShader* vertex_shader = reinterpret_cast<VertexShader*>(vertex_shader_);
  vertex_shader->SetModelMatrix(matrix);
}