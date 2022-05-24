#pragma once

class IApplication {
 public:
  virtual ~IApplication() = default;

  virtual void Initialize() = 0;

  virtual void Update(float dt) = 0;

  virtual void Draw() = 0;

  virtual void Finalize() = 0;
};