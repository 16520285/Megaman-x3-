#pragma once

#include "ShurikenData.h"
#include "ShurikenState.h"
#include "../../Entity.h"
#include <map>

class ShurikenState // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Moving,
		Stick,
		Die
	};

	~ShurikenState();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;


protected:
	ShurikenState(ShurikenData *ShurikenData);
	ShurikenState();
	int count, time;
	ShurikenData *mShurikenData;
};