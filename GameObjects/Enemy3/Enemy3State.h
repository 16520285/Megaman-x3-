#pragma once

#include "Enemy3Data.h"
#include "../Entity.h"
#include <map>

class Enemy3State // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Standing,
		Flying,
		Shooting,
		Die
		
	};

	~Enemy3State();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;


protected:
	Enemy3State(Enemy3Data *EnemyData3);
	Enemy3State();
	int count, time;
	Enemy3Data *mEnemyData3;
};