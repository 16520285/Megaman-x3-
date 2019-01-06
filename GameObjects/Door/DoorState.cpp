#include "DoorState.h"


DoorState::DoorState(DoorData *DoorData)
{
	this->mDoorData = DoorData;
}

DoorState::DoorState()
{
}
DoorState::~DoorState()
{
}

void DoorState::Update(float dt)
{

}

void DoorState::HandleKeyboard(std::map<int, bool> keys)
{

}
void DoorState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}