#pragma once

#include "PlayerBulletData.h"

#include "../Entity.h"
#include <map>

class BulletState // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Moving,
		Die
		
	};

	~BulletState();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;


protected:
	//BulletState(PlayerBulletData *EnemyData3);
	BulletState();
	int count, time;
	//PlayerBulletData *playerBulletData;

};