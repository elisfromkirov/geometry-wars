#pragma once

#include <entity_component/entity_handle.hpp>

#include <renderer/components.hpp>

#include <list>

class Scene {
 public:
  class Iterator {
   public:
    typedef std::list<EntityHandle>::iterator IteratorImpl;

   public:
    Iterator(IteratorImpl impl);

    bool operator==(const Iterator& other);
    bool operator!=(const Iterator& other);

    Iterator& operator++();
    Iterator operator++(int unused);

    Matrix3x3f GetModelMatrix();

    VertexBuffer* GetVertexBuffer();

   private:
    IteratorImpl impl_;
  };

 public:
  Iterator Begin();
  Iterator End();

  bool Attach(EntityHandle handle);
  bool Detach(EntityHandle handle);

 private:
  std::list<EntityHandle> entities_;
};