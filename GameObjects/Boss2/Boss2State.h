#pragma once

#include "Boss2Data.h"
#include "../Entity.h"
#include <map>

class Boss2State // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Standing,
		Attack,
		Shooting,
		Die
		

	};

	~Boss2State();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;


protected:
	Boss2State(Boss2Data *Boss2Data);
	Boss2State();
	int count, time;
	Boss2Data *mBoss2Data;
};