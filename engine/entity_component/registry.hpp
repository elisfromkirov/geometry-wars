#pragma once

#include <entity_component/component_holder.hpp>
#include <entity_component/generator.hpp>

#include <cassert>
#include <cstdint>
#include <unordered_map>

typedef std::uint64_t EntityId;

typedef IdGenerator<EntityId> EntityIdGenerator;

class EntityRegistry {
 public:
  static constexpr EntityId InvalidId{0};

 public:
  EntityId CreateEntity();

  void DestroyEntity(EntityId id);

  void DestroyAllEntities();

  template <typename ComponentT, typename... Args>
  void AddComponent(EntityId id, Args&&... args);

  template <typename ComponentT>
  void RemoveComponent(EntityId id);

  template <typename ComponentT>
  ComponentT* GetComponent(EntityId id);

  template <typename ComponentT>
  bool HasComponent(EntityId id);

 private:
  using EntityMap = std::unordered_map<EntityId, IComponentHolder*>;
  using ComponentMap = std::unordered_map<ComponentTypeId, IComponentHolder*>;

  using EntityStorage = std::unordered_map<EntityId, ComponentMap>;
  using ComponentStorage = std::unordered_map<ComponentTypeId, EntityMap>;

 private:
  EntityStorage entities_;
  ComponentStorage components_;
  EntityIdGenerator entity_id_generator_;
};

///////////////////////////////////////////////////////////////////////////////

#include <entity_component/registry.ipp>

///////////////////////////////////////////////////////////////////////////////