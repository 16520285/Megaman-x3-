#pragma once

#include "Enemy2.h"
#include "EnemyData2.h"
#include "Enemy2State.h"

class Enemy2ShootingState : public Enemy2State
{
public:
	Enemy2ShootingState(EnemyData2 *playerData);
	~Enemy2ShootingState();

	void Update(float dt);

	//void HandleKeyboard(std::map<int, bool> keys);

	//void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	virtual StateName GetState();

protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorY;
	float acceleratorX;
	bool noPressed;
	bool allowMoveRight, allowMoveLeft;
};

