#pragma once

#include <collision/collision_geometry.hpp>
#include <collision/collision_event.hpp>

#include <cassert>
#include <vector>

class CollisionDetector {
 public:
  bool Register(CollisionGeometry* geometry, CollisionEventCallback callback);
  bool Unregister(CollisionGeometry* geometry);

  void Detect();

 private:
  bool CollisionTest(CollisionGeometry* lhs, CollisionGeometry* rhs);

 private:
  struct CollidableBodyDesc {
    CollisionGeometry* geometry;
    CollisionEventCallback callback;
  };
  std::vector<CollidableBodyDesc> bodies_; 
};