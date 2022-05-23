template <typename Vertex>
BasicVertexBuffer<Vertex>::BasicVertexBuffer(Vertex* buffer, std::uint64_t size)
    : buffer_{buffer},
      size_{size} {
  assert(buffer_ != nullptr);
}

template <typename Vertex>
Vertex* BasicVertexBuffer<Vertex>::GetBuffer() const {
  return buffer_;
}

template <typename Vertex>
std::uint64_t BasicVertexBuffer<Vertex>::GetSize() const {
  return size_;
}