#pragma once

#include <function/invokable.hpp>

#include <utility>

template <typename R, typename ...Args>
class Function;

template <typename R, typename ...Args>
class Function<R(Args...)> : public IInvokable<R(Args...)> {
public:
  typedef R (*FunctionPointer)(Args...);

public:
  explicit Function(FunctionPointer function);

  R Invoke(Args&&... args) override;

private:
  FunctionPointer function_;
}; 

///////////////////////////////////////////////////////////////////////////////

#include <function/function.ipp>

///////////////////////////////////////////////////////////////////////////////