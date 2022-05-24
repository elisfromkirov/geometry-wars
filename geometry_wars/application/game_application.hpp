#pragma once

#include <application/application_base.hpp>

#include <collision/collision_detector.hpp>

#include <game/game_command_executor.hpp>
#include <game/move_command.hpp>

#include <renderer/components.hpp>
#include <renderer/program.hpp>
#include <renderer/renderer.hpp>
#include <renderer/scene.hpp>
#include <renderer/shaders.hpp>

class GameApplication : public ApplicationBase {
 public:
  void Initialize() override;

  void Update(float dt) override;

  void Draw() override;

  void Finalize() override;

 private:
  EntityRegistry registry_;
  EntityHandle handle_;

  VertexShader vertex_shader_;
  FragmentShader fragment_shader_;
  Program program_;
  Renderer renderer_;
  Scene scene_;

  CollisionDetector collision_detector_;

  GameCommandExecutor command_executor_;
};