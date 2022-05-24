#include <game/game_command_executor.hpp>

void GameCommandExecutor::Execute() {
  while (!command_queue_.empty()) {
    IGameCommand* command = command_queue_.front();
    command_queue_.pop();

    command->Execute();

    delete command; 
  }
}