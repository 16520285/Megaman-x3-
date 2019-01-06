#include "EnemyState.h"


EnemyState::EnemyState(EnemyData1 *enemyData)
{
	this->mEnemyData = enemyData;
}

EnemyState::EnemyState() {
}
EnemyState::~EnemyState()
{
}

void EnemyState::Update(float dt)
{

}

void EnemyState::HandleKeyboard(std::map<int, bool> keys)
{

}
void EnemyState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}