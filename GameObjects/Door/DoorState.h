#pragma once
#pragma once

#include "DoorState.h"
#include "../../GameObjects/Entity.h"
#include <map>
#include "DoorData.h"

class DoorState // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Open,
		Close,
		Closed,
		Standing,
		Opened
	};

	~DoorState();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;

protected:
	DoorState(DoorData *DoorData);
	DoorState();
	int count, time;
	DoorData *mDoorData;
};