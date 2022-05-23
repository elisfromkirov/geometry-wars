#pragma once

#include <utility>

template <typename R, typename... Args>
class InvokableOwner;

template <typename R, typename... Args>
class InvokableOwner<R(Args...)> {
 public:
  typedef IInvokable<R(Args...)>* InvokableImplPointer;
 
 public:
  InvokableOwner(InvokableImplPointer pimpl = nullptr);

  InvokableOwner(const InvokableOwner& other) = delete;
  InvokableOwner& operator=(const InvokableOwner& other) = delete;

  InvokableOwner(InvokableOwner&& other) noexcept;
  InvokableOwner& operator=(InvokableOwner&& other) noexcept;

  ~InvokableOwner();

 protected:
  void Swap(InvokableOwner& other) noexcept;

  template <typename InvokableImpl, typename... ConstructorArgs>
  void Reset(ConstructorArgs&&... args);

  void Reset(InvokableImplPointer pimpl);

 protected:
  InvokableImplPointer pimpl_;
};

///////////////////////////////////////////////////////////////////////////////

#include <function/invokable_owner.ipp>

///////////////////////////////////////////////////////////////////////////////