#pragma once

class IGameCommand {
 public:
  virtual ~IGameCommand() = default;

  virtual void Execute() = 0;
};