#include <application/application.hpp>

#include <framework/engine.hpp>

#include <cassert>

static IApplication* kApplication{nullptr};

void initialize() {
  assert(kApplication != nullptr);
  
  kApplication->Initialize();
}

void act(float dt) {
  assert(kApplication != nullptr);
  
  kApplication->Update(dt);
}

void draw() {
  assert(kApplication != nullptr);
  
  kApplication->Draw();
}

void finalize() {
  assert(kApplication != nullptr);
  
  kApplication->Finalize();
}

///////////////////////////////////////////////////////////////////////////////

#include <application/application_base.hpp>

ApplicationBase::ApplicationBase()
    : framebuffer_{reinterpret_cast<std::uint32_t*>(buffer), SCREEN_WIDTH, SCREEN_HEIGHT} {
  kApplication = this;
}

void ApplicationBase::Initialize() {
}

void ApplicationBase::Update(float dt) {
}

void ApplicationBase::Draw() {
}

void ApplicationBase::Finalize() {
}

bool ApplicationBase::IsKeyPressed(VirtualKey key) const {
  switch (key) {
    case VirtualKey::kEscape:      return is_key_pressed(VK_ESCAPE);
    case VirtualKey::kSpace:       return is_key_pressed(VK_SPACE );
    case VirtualKey::kLeftArrow:   return is_key_pressed(VK_LEFT  );
    case VirtualKey::kRightArrow:  return is_key_pressed(VK_RIGHT );
    case VirtualKey::kUpArrow:     return is_key_pressed(VK_UP    );
    case VirtualKey::kDownArrow:   return is_key_pressed(VK_DOWN  );
    case VirtualKey::kReturnArrow: return is_key_pressed(VK_RETURN);
  }
  return false;
}

bool ApplicationBase::IsMouseButtonPressed(MouseButton button) const {
  switch (button) {
    case MouseButton::kLeft: return is_mouse_button_pressed(0);
    case MouseButton::kRight: return is_mouse_button_pressed(1);
    case MouseButton::kMiddle: return is_mouse_button_pressed(1);
  }
  return false;
}

Vector2i ApplicationBase::GetMousePosition() const {
  return Vector2i{get_cursor_x(), get_cursor_y()};
}

void ApplicationBase::ScheduleQuit() const {
  schedule_quit_game();
}