#pragma once
#pragma once

#include "BrickState.h"
#include "../../GameObjects/Entity.h"
#include <map>
#include "BrickData.h"

class BrickState // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Standing,
		Die
	};

	~BrickState();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;

protected:
	BrickState(BrickData *BrickData);
	BrickState();
	int count, time;
	BrickData *mBrickData;
};