#include <renderer/scene.hpp>

Scene::Iterator::Iterator(IteratorImpl impl)
    : impl_{impl} {
}

bool Scene::Iterator::operator==(const Iterator& other) {
  return impl_ == other.impl_;
}

bool Scene::Iterator::operator!=(const Iterator& other) {
  return impl_ != other.impl_;
}

Scene::Iterator& Scene::Iterator::operator++() {
  impl_++;
  return *this;
}

Scene::Iterator Scene::Iterator::operator++(int unused) {
  Iterator iter{impl_};
  impl_++;
  return iter;
}

Matrix3x3f Scene::Iterator::GetModelMatrix() {
  return impl_->GetComponent<TransformComponent>()->GetModelMatrix();
}

VertexBuffer* Scene::Iterator::GetVertexBuffer() {
  return impl_->GetComponent<MeshComponent>()->GetVertexBuffer();
}

Scene::Iterator Scene::Begin() {
  return Iterator{entities_.begin()};
}

Scene::Iterator Scene::End() {
  return Iterator{entities_.end()};
}

bool Scene::Attach(EntityHandle handle) {
  if (!handle.HasComponent<TransformComponent>()) {
    return false;
  }
  if (!handle.HasComponent<MeshComponent>()) {
    return false;
  }

  entities_.push_back(handle);
  return true;
}

bool Scene::Detach(EntityHandle handle) {
  return false;
}