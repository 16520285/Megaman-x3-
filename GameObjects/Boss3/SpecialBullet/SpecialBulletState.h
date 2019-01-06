#pragma once

#include "SpecialBulletData.h"
#include "SpecialBulletState.h"
#include "../../Entity.h"
#include <map>

class SpecialBulletState // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Flying,
		Die
		

	};

	~SpecialBulletState();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;


protected:
	SpecialBulletState(SpecialBulletData *SpecialBulletData);
	SpecialBulletState();
	int count, time;
	SpecialBulletData *mSpecialBulletData;
};