template <typename T, typename R, typename... Args>
Method<T, R(Args...)>::Method(
  typename Method<T, R(Args...)>::ObjectPointer object,
  typename Method<T, R(Args...)>::MethodPointer method)
    : object_{object},
      method_{method} {
}

template <typename T, typename R, typename... Args>
R Method<T, R(Args...)>::Invoke(Args&&... args) {
  return (object_->*method_)(std::forward<Args>(args)...);
} 