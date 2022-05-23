#pragma once

#include <cstdint>

struct Framebuffer {
  std::uint32_t* data;
  std::uint64_t width;
  std::uint64_t height;
};