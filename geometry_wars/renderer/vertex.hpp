#pragma once

#include <math/vector3.hpp>

#include <renderer_back_end/basic_vertex_buffer.hpp>

struct Vertex {
  Vector3f data;
};

typedef BasicVertexBuffer<Vertex> VertexBuffer;