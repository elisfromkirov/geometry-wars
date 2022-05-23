#pragma once

#include <function/delegate.hpp>

struct Body;

struct MoveEvent {
  Body* body;
  Vector2f distance; 
};

typedef Delegate<void(MoveEvent*)> MoveEventCallback;

///////////////////////////////////////////////////////////////////////////////

struct CollisionEvent {
  Body* bodies[2];
};

typedef Delegate<void(CollisionEvent*)> CollisionEventCallback;