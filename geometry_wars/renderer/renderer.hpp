#pragma once

#include <renderer_back_end/framebuffer.hpp>

#include <renderer/program.hpp>
#include <renderer/vertex.hpp>
#include <renderer/scene.hpp>

class Renderer {
 public:
  void SetFramebuffer(const Framebuffer& framebuffer);

  void UseProgram(Program* program);

  void Clear();

  void Render(Scene* scene);

 private:
  Framebuffer framebuffer_;
  Program* program_;
};