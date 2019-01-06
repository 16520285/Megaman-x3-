#include "Brick2State.h"


Brick2State::Brick2State(Brick2Data *Brick2Data)
{
	this->mBrick2Data = Brick2Data;
}

Brick2State::Brick2State()
{
}
Brick2State::~Brick2State()
{
}

void Brick2State::Update(float dt)
{

}

void Brick2State::HandleKeyboard(std::map<int, bool> keys)
{

}
void Brick2State::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}