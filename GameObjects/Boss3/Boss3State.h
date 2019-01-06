#pragma once

#include "Boss3Data.h"
#include "../Entity.h"
#include <map>

class Boss3State // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Flying,
		Attack,
		GenerateBee,
		Preparing,
		Born,
		Die, 
		ZiczacBee,
		Standing

	};

	~Boss3State();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;


protected:
	Boss3State(Boss3Data *Boss3Data);
	Boss3State();
	int count, clock;
	Boss3Data *mBoss3Data;
};