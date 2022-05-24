#pragma once

#include <game/game_command.hpp>

#include <cassert>
#include <queue>

class GameCommandExecutor {
 public:
  template <typename GameCommandT, typename... ConstructorArgs>
  void Submit(ConstructorArgs&&... args);

  void Execute();

 private:
  std::queue<IGameCommand*> command_queue_;
};

template <typename GameCommandT, typename... ConstructorArgs>
void GameCommandExecutor::Submit(ConstructorArgs&&... args) {
  command_queue_.push(new GameCommandT(std::forward<ConstructorArgs>(args)...));
}