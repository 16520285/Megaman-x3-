#pragma once

#include "../../GameObjects/Enemy/EnemyData1.h"
#include "../../GameObjects/Entity.h"
#include <map>

class EnemyState // Chi dung doi voi cac Enemy co cac trang thai di chuyen, tan cong
{
public:
	enum StateName
	{
		Standing,
		Shooting,
		Die
	};

	~EnemyState();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;

protected:
	EnemyState(EnemyData1 *enemyData);
	EnemyState();

	EnemyData1 *mEnemyData;
};