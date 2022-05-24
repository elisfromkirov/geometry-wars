#pragma once

#include <collision/collision_geometry.hpp>

#include <function/delegate.hpp>

struct CollisionEvent {
  CollisionGeometry* first;
  CollisionGeometry* second;
};

typedef Delegate<void(CollisionEvent&)> CollisionEventCallback;