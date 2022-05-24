#include <application/game_application.hpp>

#include <iostream>

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
  buffer[0] = { 0.1, 0.0f, 1.0f};
  buffer[1] = {-0.1, 0.0f, 1.0f};
  buffer[2] = { 0.0, 0.1f, 1.0f};

  handle_ = CreateEntity(registry_);
  handle_.AddComponent<TransformComponent>();
  handle_.AddComponent<MeshComponent>(buffer, 3);
  handle_.AddComponent<CollisionGeometry>(CollisionGeometry{Vector2f{0.f, 0.f}, 0.5f});

  scene_.Attach(handle_);
}

void GameApplication::Update(float dt) {
  if (IsKeyPressed(VirtualKey::kEscape)) {
    ScheduleQuit();
  }
  if (IsKeyPressed(VirtualKey::kLeftArrow)) {
    command_executor_.Submit<MoveCommand>(handle_, Vector2f{-0.02f, 0.0f});
  }
  if (IsKeyPressed(VirtualKey::kRightArrow)) {
    command_executor_.Submit<MoveCommand>(handle_, Vector2f{ 0.02f, 0.0f});
  }
  if (IsKeyPressed(VirtualKey::kUpArrow)) {
    command_executor_.Submit<MoveCommand>(handle_, Vector2f{ 0.0f, 0.02f});
  }
  if (IsKeyPressed(VirtualKey::kDownArrow)) {
    command_executor_.Submit<MoveCommand>(handle_, Vector2f{ 0.0f,-0.02f});
  }

  command_executor_.Execute();
}

void GameApplication::Draw() {
  renderer_.Clear();
  renderer_.Render(&scene_);
}

void GameApplication::Finalize() {
}