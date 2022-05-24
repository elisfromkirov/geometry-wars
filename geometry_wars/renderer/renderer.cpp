#include <renderer/renderer.hpp>

void Renderer::SetFramebuffer(const Framebuffer& framebuffer) {
  framebuffer_ = framebuffer;
}

void Renderer::UseProgram(Program* program) {
  program_ = program;
}

void Renderer::Clear() {
  for (std::uint64_t i = 0; i < framebuffer_.width * framebuffer_.height; ++i) {
    framebuffer_.data[i] = 0x00ffffff;
  }
}

void Renderer::Render(Scene* scene) {
  assert(program_ != nullptr);
  assert(scene != nullptr);

  for (auto iter = scene->Begin(); iter != scene->End(); ++iter) {
    program_->UpdateModelMatrix(iter.GetModelMatrix());
    program_->BindVertexBuffer(iter.GetVertexBuffer());
    program_->Execute(&framebuffer_);
  }
}