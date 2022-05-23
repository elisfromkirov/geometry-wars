#pragma once

#include <renderer_back_end/framebuffer.hpp>

class IProgram {
 public:
  virtual ~IProgram() = default;

  virtual void Execute(Framebuffer* framebuffer) = 0;
};