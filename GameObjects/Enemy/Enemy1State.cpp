#include "Enemy1State.h"


Enemy1State::Enemy1State(EnemyData1 *enemyData1)
{
	this->mEnemyData1 = enemyData1;
}

Enemy1State::Enemy1State()
{
}
Enemy1State::~Enemy1State()
{
}

void Enemy1State::Update(float dt)
{
	
}

void Enemy1State::HandleKeyboard(std::map<int, bool> keys)
{

}
void Enemy1State::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}