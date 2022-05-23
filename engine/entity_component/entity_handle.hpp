#pragma once

#include <entity_component/registry.hpp>

class EntityHandle {
 public:
  EntityHandle(EntityId id, EntityRegistry* registry);

  void Destroy();

  template <typename ComponentT, typename... Args>
  void AddComponent(Args&&... args);

  template <typename ComponentTy>
  void RemoveComponent();

  template <typename ComponentT>
  ComponentT* GetComponent();

  template <typename ComponentT>
  bool HasComponent();

 private:
  EntityId id_;
  EntityRegistry* registry_;
};

///////////////////////////////////////////////////////////////////////////////

#include <entity_component/entity_handle.hpp>

///////////////////////////////////////////////////////////////////////////////

EntityHandle CreateEntity(EntityRegistry& registry);