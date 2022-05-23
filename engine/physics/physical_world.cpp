#include <physics/physical_world.hpp>

void PhysicalWorld::Simulate(float dt) {
  for (auto iter = bodies_.begin(); iter != bodies_.end(); ++iter) {
    Vector2f distance{iter->body->velocity * dt};
    
    iter->body->position += distance;
    
    MoveEvent move_event{iter->body, distance};
    if (iter->behaviour.move_event_callback.IsBound()) {
      iter->behaviour.move_event_callback(&move_event);
    }
  }
}

void PhysicalWorld::Register(Body* body, BodyBehaviour behaviour) {
  assert(body != nullptr);

  bodies_.push_back(BodyDesc{body, std::move(behaviour)});
}

void PhysicalWorld::Unregister(Body* body) {
  for (auto iter = bodies_.begin(); iter != bodies_.end(); ++iter) {
    if (iter->body == body) {
      bodies_.erase(iter);
      break;
    }
  }
}