template <typename R, typename... Args>
InvokableOwner<R(Args...)>::InvokableOwner(InvokableImplPointer impl) 
    : pimpl_{impl} {
}

template <typename R, typename... Args>
InvokableOwner<R(Args...)>::InvokableOwner(InvokableOwner&& other) noexcept
    : pimpl_{other.pimpl_} {
  other.pimpl_ = nullptr;
}

template <typename R, typename... Args>
InvokableOwner<R(Args...)>& InvokableOwner<R(Args...)>::operator=(InvokableOwner&& other) noexcept {
  if (this != &other) {
    InvokableOwner temp(std::move(other));
    Swap(temp);
  }
  return *this;
}

template <typename R, typename... Args>
InvokableOwner<R(Args...)>::~InvokableOwner() {
  delete pimpl_;
}

template <typename R, typename... Args>
void InvokableOwner<R(Args...)>::Swap(InvokableOwner& other) noexcept {
  std::swap(pimpl_, other.pimpl_);
} 

template <typename R, typename... Args>
template <typename InvokableImpl, typename... ConstructorArgs>
void InvokableOwner<R(Args...)>::Reset(ConstructorArgs&&... args) {
  InvokableOwner temp(new InvokableImpl(std::forward<ConstructorArgs>(args)...));
  Swap(temp);
}

template <typename R, typename... Args>
void InvokableOwner<R(Args...)>::Reset(InvokableImplPointer pimpl) {
  InvokableOwner temp(pimpl);
  Swap(temp);
}