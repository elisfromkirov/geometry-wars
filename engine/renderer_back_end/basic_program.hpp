#pragma once

#include <renderer_back_end/basic_fragment_shader.hpp>
#include <renderer_back_end/basic_vertex_buffer.hpp>
#include <renderer_back_end/basic_vertex_shader.hpp>
#include <renderer_back_end/program.hpp>

#include <cassert>
#include <cmath>

template <typename Vertex>
class BasicProgram : public IProgram {
 public:
  typedef BasicVertexBuffer<Vertex> VertexBuffer;
  typedef BasicFragmentShader<Vertex> FragmentShader; 
  typedef BasicVertexShader<Vertex> VertexShader;

 public:
  BasicProgram(VertexBuffer* vertex_buffer, VertexShader* vertex_shader, FragmentShader* fragment_shader);

  void Execute(Framebuffer* framebuffer) override;

 private:
  Vector2i MapVertexCoordinates(Framebuffer* framebuffer, Vector3f vertex);

  std::uint32_t MapColor(Vector3f color);

  void Draw(Framebuffer* framebuffer, Vector2i a, Vector2i b);

 private:
  VertexBuffer* vertex_buffer_;
  FragmentShader* fragment_shader_;
  VertexShader* vertex_shader_;
};

///////////////////////////////////////////////////////////////////////////////

#include <renderer_back_end/basic_program.ipp>

///////////////////////////////////////////////////////////////////////////////