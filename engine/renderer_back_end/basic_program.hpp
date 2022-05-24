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
  void BindVertexShader(BasicVertexShader<Vertex>* vertex_shader);

  void BindFragmentShader(BasicFragmentShader<Vertex>* fragment_shader);

  void BindVertexBuffer(BasicVertexBuffer<Vertex>* vertex_buffer);

  void Execute(Framebuffer* framebuffer) override;  

 protected:
  Vector2i MapVertexCoordinates(Framebuffer* framebuffer, Vector3f vertex);

  std::uint32_t MapColor(Vector3f color);

  void Draw(Framebuffer* framebuffer, Vector2i a, Vector2i b);

 protected:
  BasicVertexShader<Vertex>* vertex_shader_;
  BasicFragmentShader<Vertex>* fragment_shader_;
  BasicVertexBuffer<Vertex>* vertex_buffer_;
};

///////////////////////////////////////////////////////////////////////////////

#include <renderer_back_end/basic_program.ipp>

///////////////////////////////////////////////////////////////////////////////