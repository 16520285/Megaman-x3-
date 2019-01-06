#pragma once
#pragma once

#include "Brick2State.h"
#include "../../GameObjects/Entity.h"
#include <map>
#include "Brick2Data.h"

class Brick2State // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Standing,
		Die
	};

	~Brick2State();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;

protected:
	Brick2State(Brick2Data *Brick2Data);
	Brick2State();
	int count, time;
	Brick2Data *mBrick2Data;
};