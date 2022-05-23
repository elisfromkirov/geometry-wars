template <typename R, typename... Args>
R Delegate<R(Args...)>::operator()(Args&&... args) {
  return this->pimpl_->Invoke(std::forward<Args>(args)...);
}

template <typename R, typename... Args>
bool Delegate<R(Args...)>::IsBound() const {
  return this->pimpl_ != nullptr;
}

template <typename R, typename... Args>
template <typename InvokableImpl, typename... ConstructorArgs>
bool Delegate<R(Args...)>::Bind(ConstructorArgs&&... args) {
  if (this->pimpl_ != nullptr) {
    return false;
  }

  this->template Reset<InvokableImpl, ConstructorArgs...>(std::forward<ConstructorArgs>(args)...);
  return true;
}

template <typename R, typename... Args>
void Delegate<R(Args...)>::Unbind() {
  this->Reset(nullptr);
}