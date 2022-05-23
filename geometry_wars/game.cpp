#include <framework/engine.hpp>

#include <math/matrix3x3.hpp>
#include <math/vector2.hpp>
#include <math/vector3.hpp>

#include <physics/physical_body.hpp>
#include <physics/physical_event.hpp>
#include <physics/physical_world.hpp>

void initialize() {
}

void act(float dt) {
  if (is_key_pressed(VK_ESCAPE))
    schedule_quit_game();
}

void draw() {
  for (std::uint64_t i = 0; i < SCREEN_HEIGHT; ++i) {
    for (std::uint64_t j = 0; j < SCREEN_WIDTH; ++j) {
      buffer[i][j] = 0x0000ff;
    }
  }
}

void finalize() {
}