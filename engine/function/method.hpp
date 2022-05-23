#pragma once

#include <function/invokable.hpp>

#include <utility>

template <typename T, typename R, typename... Args>
class Method;

template <typename T, typename R, typename... Args>
class Method<T, R(Args...)> : public IInvokable<R(Args...)> {
 public:
  typedef T* ObjectPointer;
  typedef R (T::*MethodPointer)(Args...);

 public:
  explicit Method(ObjectPointer object, MethodPointer method);

  R Invoke(Args&&... args) override;

private:
  ObjectPointer object_;
  MethodPointer method_;
};

///////////////////////////////////////////////////////////////////////////////

#include <function/method.ipp>

///////////////////////////////////////////////////////////////////////////////