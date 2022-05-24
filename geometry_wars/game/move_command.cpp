#include <collision/collision_geometry.hpp>

#include <game/move_command.hpp>

#include <renderer/components.hpp>

MoveCommand::MoveCommand(EntityHandle handle, Vector2f displacement)
    : handle_{handle},
      displacement_{displacement} {
}

void MoveCommand::Execute() {
  UpdateTransformComponent();
  UpdateCollisionGeometry();
}

void MoveCommand::UpdateTransformComponent() {
  TransformComponent* transform{handle_.GetComponent<TransformComponent>()};
  assert(transform != nullptr);

  transform->SetPosition(transform->GetPosition() + displacement_);
}

void MoveCommand::UpdateCollisionGeometry() {
  CollisionGeometry* geometry{handle_.GetComponent<CollisionGeometry>()};
  assert(geometry != nullptr);

  geometry->position += displacement_;
}