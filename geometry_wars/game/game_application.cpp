#include <game/game_application.hpp>

static GameApplication kGameApplication{}; 

void GameApplication::Initialize() {
  float a{static_cast<float>(framebuffer_.height) / static_cast<float>(framebuffer_.width)};

  vertex_shader_.SetProjMatrix(Matrix3x3f{
    Vector3f{  a, 0.f, 0.f},
    Vector3f{0.f, 1.f, 0.f},
    Vector3f{0.f, 0.f, 1.f}
  });

  program_.BindVertexShader(&vertex_shader_);
  program_.BindFragmentShader(&fragment_shader_);

  renderer_.SetFramebuffer(framebuffer_);
  renderer_.UseProgram(&program_);

  Vertex* buffer = new Vertex[3];
  buffer[0] = { 0.5, 0.0f, 1.0f};
  buffer[1] = {-0.5, 0.0f, 1.0f};
  buffer[2] = { 0.0, 0.5f, 1.0f};

  EntityHandle handle{CreateEntity(registry_)};
  handle.AddComponent<TransformComponent>();
  handle.AddComponent<MeshComponent>(buffer, 3);

  scene_.Attach(handle);
}

void GameApplication::Update(float dt) {
}

void GameApplication::Draw() {
  renderer_.Clear();
  renderer_.Render(&scene_);
}

void GameApplication::Finalize() {
}