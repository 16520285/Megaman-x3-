#include "Enemy3State.h"


Enemy3State::Enemy3State(Enemy3Data *Enemy3Data)
{
	this->mEnemyData3 = Enemy3Data;
}

Enemy3State::Enemy3State()
{
}
Enemy3State::~Enemy3State()
{
}

void Enemy3State::Update(float dt)
{
	
}

void Enemy3State::HandleKeyboard(std::map<int, bool> keys)
{

}
void Enemy3State::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}