#pragma once

#include <physics/physical_body.hpp>
#include <physics/physical_event.hpp>

#include <cassert>
#include <list>

class PhysicalWorld {
 public:
  void Simulate(float dt);

  void Register(Body* body, BodyBehaviour behaviour);
  void Unregister(Body* body);

 private:
  struct BodyDesc {
    Body* body;
    BodyBehaviour behaviour;
  };

  std::list<BodyDesc> bodies_;
};