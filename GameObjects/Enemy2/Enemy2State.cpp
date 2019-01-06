#include "Enemy2State.h"


Enemy2State::Enemy2State(EnemyData2 *enemyData2)
{
	this->mEnemyData2 = enemyData2;
}

Enemy2State::Enemy2State()
{
}
Enemy2State::~Enemy2State()
{
}

void Enemy2State::Update(float dt)
{

}

void Enemy2State::HandleKeyboard(std::map<int, bool> keys)
{

}
void Enemy2State::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}