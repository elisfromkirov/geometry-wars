#pragma once

#include <math/vector2.hpp>

#include <physics/physical_event.hpp>

struct Body {
  Vector2f position;
  Vector2f velocity;
  float radius;
};

struct BodyBehaviour {
  MoveEventCallback move_event_callback;
  CollisionEventCallback collision_event_callback;
};