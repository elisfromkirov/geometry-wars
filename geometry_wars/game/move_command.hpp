#pragma once

#include <entity_component/entity_handle.hpp>

#include <game/game_command.hpp>

#include <math/vector2.hpp>

#include <cassert>

class MoveCommand : public IGameCommand {
 public:
  MoveCommand(EntityHandle handle, Vector2f displacement);

  void Execute() override;

 private:
  void UpdateTransformComponent();

  void UpdateCollisionGeometry();

 private:
  EntityHandle handle_;
  Vector2f displacement_;
};