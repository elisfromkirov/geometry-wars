template <typename R, typename... Args>
Function<R(Args...)>::Function(
  typename Function<R(Args...)>::FunctionPointer function)
    : function_{function} {
}

template <typename R, typename... Args>
R Function<R(Args...)>::Invoke(Args&&... args) {
  return function_(std::forward<Args>(args)...);
}