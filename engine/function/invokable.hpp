#pragma once

template <typename R, typename... Args>
class IInvokable;

template <typename R, typename... Args>
class IInvokable<R(Args...)> {
 public:
  virtual ~IInvokable() = default;

  virtual R Invoke(Args&&... args) = 0;
};