#pragma once

#include <application/application.hpp>

#include <math/vector2.hpp>

#include <renderer_back_end/framebuffer.hpp>

enum class VirtualKey {
  kEscape,
  kSpace,
  kLeftArrow,
  kRightArrow,
  kUpArrow,
  kDownArrow,
  kReturnArrow
};

enum class MouseButton {
  kLeft,
  kRight,
  kMiddle
};

class ApplicationBase : public IApplication {
 public:
  ApplicationBase();

  void Initialize() override;

  void Update(float dt) override;

  void Draw() override;

  void Finalize() override;

 protected:
  bool IsKeyPressed(VirtualKey key) const;

  bool IsMouseButtonPressed(MouseButton button) const;
  
  Vector2i GetMousePosition() const;

  void ScheduleQuit() const;

 protected:
  Framebuffer framebuffer_;
};