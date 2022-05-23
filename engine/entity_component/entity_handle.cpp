#include <entity_component/entity_handle.hpp>

EntityHandle::EntityHandle(EntityId id, EntityRegistry* registry) 
    : id_{id}, 
      registry_{registry} {
}

void EntityHandle::Destroy() {
  assert(registry_ != nullptr);

  registry_->DestroyEntity(id_); 
}

EntityHandle CreateEntity(EntityRegistry& registry) {
  return EntityHandle{registry.CreateEntity(), &registry};
}