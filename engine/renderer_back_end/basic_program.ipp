template <typename Vertex>
void BasicProgram<Vertex>::BindVertexShader(BasicVertexShader<Vertex>* vertex_shader) {
  vertex_shader_ = vertex_shader;
}

template <typename Vertex>
void BasicProgram<Vertex>::BindFragmentShader(BasicFragmentShader<Vertex>* fragment_shader) {
  fragment_shader_ = fragment_shader;
}

template <typename Vertex>
void BasicProgram<Vertex>::BindVertexBuffer(BasicVertexBuffer<Vertex>* vertex_buffer) {
  vertex_buffer_ = vertex_buffer;
}

template <typename Vertex>
void BasicProgram<Vertex>::Execute(Framebuffer* framebuffer) {
  assert(vertex_shader_ != nullptr);
  assert(fragment_shader_ != nullptr);
  assert(vertex_buffer_ != nullptr);
  assert(framebuffer != nullptr);

  Vertex* buffer = vertex_buffer_->GetBuffer();
  std::uint64_t size = vertex_buffer_->GetSize();

  for (std::uint64_t i = 0; i < size / 3; ++i) {
    Vector2i vertices[3] = {
      MapVertexCoordinates(framebuffer, vertex_shader_->Process(buffer[i * 3    ])),
      MapVertexCoordinates(framebuffer, vertex_shader_->Process(buffer[i * 3 + 1])),
      MapVertexCoordinates(framebuffer, vertex_shader_->Process(buffer[i * 3 + 2]))
    };

    Draw(framebuffer, vertices[0], vertices[1]);
    Draw(framebuffer, vertices[1], vertices[2]);
    Draw(framebuffer, vertices[2], vertices[0]);
  }
}

template <typename Vertex>
Vector2i BasicProgram<Vertex>::MapVertexCoordinates(Framebuffer* framebuffer, Vector3f vertex) {
  assert(framebuffer != nullptr);

  return Vector2i{
    static_cast<int>(static_cast<float>(framebuffer->width ) * (1.f + vertex.x) / 2.f),
    static_cast<int>(static_cast<float>(framebuffer->height) * (1.f - vertex.y) / 2.f)
  };
}

template <typename Vertex>
std::uint32_t BasicProgram<Vertex>::MapColor(Vector3f color) {
  std::uint32_t r = static_cast<std::uint32_t>(color.r * 255.f);
  std::uint32_t g = static_cast<std::uint32_t>(color.g * 255.f); 
  std::uint32_t b = static_cast<std::uint32_t>(color.b * 255.f); 

  return (r << 16) + (g << 8) + b;
}

template <typename Vertex>
void BasicProgram<Vertex>::Draw(Framebuffer* framebuffer, Vector2i a, Vector2i b) {
  assert(framebuffer != nullptr);

  Vector2i delta{std::abs(a.x - b.x), std::abs(a.y - b.y)};
  Vector2i sign{a.x < b.x ? 1 : -1, a.y < b.y ? 1 : -1};

  std::int32_t error = delta.x - delta.y;

  if (0 <= b.y && b.y < framebuffer->height && 0 <= b.x && b.x < framebuffer->width) {
    framebuffer->data[b.y * framebuffer->width + b.x] = MapColor(fragment_shader_->Process(Vector2i{b.x, b.y}));
  }
  while (a.x != b.x || a.y != b.y) {
    if (0 <= a.y && a.y < framebuffer->height && 0 <= a.x && a.x < framebuffer->width) {
      framebuffer->data[a.y * framebuffer->width + a.x] = MapColor(fragment_shader_->Process(Vector2i{a.x, a.y}));
    }

    int32_t error2 = error * 2;
    if(error2 > -delta.y) {
      error -= delta.y;
      a.x += sign.x;
    }
    if(error2 < delta.x) {
      error += delta.x;
      a.y += sign.y;
    }
  }
}