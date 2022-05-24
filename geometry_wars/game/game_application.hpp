#pragma once

#include <application/application_base.hpp>

#include <entity_component/entity_handle.hpp>

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

  VertexShader vertex_shader_;
  FragmentShader fragment_shader_;
  Program program_;
  Renderer renderer_;
  Scene scene_;
};