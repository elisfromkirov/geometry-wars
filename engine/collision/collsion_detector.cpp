#include <collision/collision_detector.hpp>

bool CollisionDetector::Register(CollisionGeometry* geometry, CollisionEventCallback callback) {
  assert(geometry != nullptr);
  assert(callback.IsBound());

  bodies_.push_back(CollidableBodyDesc{geometry, std::move(callback)});

  return true;
}

bool CollisionDetector::Unregister(CollisionGeometry* geometry) {
  assert(geometry != nullptr);

  return false;
}

void CollisionDetector::Detect() {
  for (std::size_t i = 0; i < bodies_.size(); ++i) {
    for (std::size_t j = i + 1; j < bodies_.size(); ++j) {
      if (!CollisionTest(bodies_[i].geometry, bodies_[j].geometry)) {
        continue;
      }

      CollisionEvent event{bodies_[i].geometry, bodies_[j].geometry};

      bodies_[i].callback(event);
      bodies_[j].callback(event);
    }
  }
}

bool CollisionDetector::CollisionTest(CollisionGeometry* lhs, CollisionGeometry* rhs) {
  assert(lhs != nullptr);
  assert(rhs != nullptr);

  Vector2f distance = lhs->position - rhs->position;

  return DotProduct(distance, distance) < lhs->radius + rhs->radius;
}