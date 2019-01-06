#pragma once

#include "Boss1Data.h"
#include "../Entity.h"
#include <map>

class Boss1State // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Standing,
		Moving,
		Born,
		MovingZiczac,
		Die,
		Horizontal,
		

	};

	~Boss1State();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;


protected:
	Boss1State(Boss1Data *Boss1Data);
	Boss1State();
	int count, time;
	Boss1Data *mBoss1Data;
};