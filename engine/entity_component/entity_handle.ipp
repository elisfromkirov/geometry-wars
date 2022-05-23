template <typename ComponentT, typename... Args>
void EntityHandle::AddComponent(Args&&... args) {
  assert(registry_ != nullptr);

  registry_->AddComponent<ComponentT>(id_, std::forward<Args>(args)...);
}

template <typename ComponentT>
void EntityHandle::RemoveComponent() {
  assert(registry_ != nullptr);

  registry_->RemoveComponent<ComponentT>(id_);
}

template <typename ComponentT>
ComponentT* EntityHandle::GetComponent() {
  assert(registry_ != nullptr);

  return registry_->GetComponent<ComponentT>(id_);
}

template <typename ComponentT>
bool EntityHandle::HasComponent() {
  assert(registry_ != nullptr);

  return registry_->HasComponent<ComponentT>(id_);
}