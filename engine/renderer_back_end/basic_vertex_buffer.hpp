#pragma once

#include <cassert>
#include <cstdint>

template <typename Vertex>
class BasicVertexBuffer {
 public:
  BasicVertexBuffer(Vertex* buffer, std::uint64_t size);

  Vertex* GetBuffer() const;

  std::uint64_t GetSize() const;

 private:
  Vertex* buffer_;
  std::uint64_t size_;
};

///////////////////////////////////////////////////////////////////////////////

#include <renderer_back_end/basic_vertex_buffer.ipp>

///////////////////////////////////////////////////////////////////////////////