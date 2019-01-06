#pragma once
#pragma once

#include "Enemy2State.h"
#include "../../GameObjects/Entity.h"
#include <map>
#include "EnemyData2.h"

class Enemy2State // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Standing,
		Shooting,
		Die
	};

	~Enemy2State();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;

protected:
	Enemy2State(EnemyData2 *enemyData2);
	Enemy2State();
	int count, time;
	EnemyData2 *mEnemyData2;
};