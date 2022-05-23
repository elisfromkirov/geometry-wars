#pragma once

#include <entity_component/generator.hpp>

#include <cstdint>
#include <utility>

typedef std::uint64_t ComponentTypeId;
typedef StaticIdGenerator<ComponentTypeId> ComponentTypeIdGenerator;

class IComponentHolder {
 public:
  virtual ~IComponentHolder() = default;
};

template <typename ComponentT>
class ComponentHolderBase : public IComponentHolder {
 public:
  template <typename... Args>
  ComponentHolderBase(Args&&... args);

  ~ComponentHolderBase() override = default;

 protected:
  ComponentT component_;
};

template <typename ComponentT>
class ComponentHolder : public ComponentHolderBase<ComponentT> {
 public:
  template <typename... Args>
  ComponentHolder(Args&&... args);

  ComponentT* Get();

  static ComponentTypeId GetTypeId();

 private:
  static ComponentTypeId type_id_;
};

///////////////////////////////////////////////////////////////////////////////

#include <entity_component/component_holder.ipp>

///////////////////////////////////////////////////////////////////////////////