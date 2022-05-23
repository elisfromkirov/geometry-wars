#pragma once

#include <function/function.hpp>
#include <function/invokable_owner.hpp>
#include <function/method.hpp>

#include <cassert>

template <typename R, typename... Args>
class Delegate;

template <typename R, typename... Args>
class Delegate<R(Args...)> : public InvokableOwner<R(Args...)> {
 public:
  R operator()(Args&&... args);

  bool IsBound() const;

  template <typename InvokableImpl, typename... ConstructorArgs>
  bool Bind(ConstructorArgs&&... args);

  void Unbind();
};

///////////////////////////////////////////////////////////////////////////////

#include <function/delegate.ipp>

///////////////////////////////////////////////////////////////////////////////