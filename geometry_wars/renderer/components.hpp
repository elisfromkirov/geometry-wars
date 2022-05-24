#pragma once

#include <math/matrix3x3.hpp>
#include <math/vector2.hpp>

#include <renderer_back_end/basic_vertex_buffer.hpp>

#include <renderer/vertex.hpp>

class TransformComponent {
 public:
  TransformComponent();

  void SetPosition(const Vector2f& position);

  void SetRotation(const float angle);

  void SetScale(const Vector2f& scale);

  Matrix3x3f GetModelMatrix() const;

 private:
  Matrix3x3f translate_;
  Matrix3x3f rotation_;
  Matrix3x3f scale_;
};

class MeshComponent {
 public:
  MeshComponent(Vertex* buffer, std::uint64_t size);

  VertexBuffer* GetVertexBuffer();

 private:
  VertexBuffer buffer_;
};