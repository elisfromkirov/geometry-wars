#include <renderer/components.hpp>

#include <cmath>

TransformComponent::TransformComponent()
  : translate_{Vector3f{1.f, 0.f, 0.f}, Vector3f{0.f, 1.f, 0.f}, Vector3f{0.f, 0.f, 1.f}},
    rotation_{Vector3f{1.f, 0.f, 0.f}, Vector3f{0.f, 1.f, 0.f}, Vector3f{0.f, 0.f, 1.f}},
    scale_{Vector3f{1.f, 0.f, 0.f}, Vector3f{0.f, 1.f, 0.f}, Vector3f{0.f, 0.f, 1.f}} {
}

void TransformComponent::SetPosition(const Vector2f& position) {
  translate_[2][0] = position[0];
  translate_[2][1] = position[1];
}

void TransformComponent::SetRotation(const float angle) {
  rotation_[0][0] =  cosf(angle);
  rotation_[0][1] =  sinf(angle);
  rotation_[1][0] = -sinf(angle);
  rotation_[1][1] =  cosf(angle);
}

void TransformComponent::SetScale(const Vector2f& scale) {
  scale_[0][0] = scale[0];
  scale_[1][1] = scale[1];
}

Matrix3x3f TransformComponent::GetModelMatrix() const {
  return translate_ * rotation_ * scale_;
}

MeshComponent::MeshComponent(Vertex* buffer, std::uint64_t size)
    : buffer_{buffer, size} {
}

VertexBuffer* MeshComponent::GetVertexBuffer() {
  return &buffer_;
}