#pragma once

#include "EnemyData1.h"
#include "../Entity.h"
#include <map>

class Enemy1State // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Standing,
		Falling,
		Jumping,
		Shooting,
		Flying,
		Die
	};

	~Enemy1State();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;


protected:
	Enemy1State(EnemyData1 *enemyData1);
	Enemy1State();
	int count, time;
	EnemyData1 *mEnemyData1;
};