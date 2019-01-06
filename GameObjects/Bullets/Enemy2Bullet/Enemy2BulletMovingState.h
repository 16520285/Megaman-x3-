#pragma once
#include "../BulletState.h"
#include "Enemy2BulletData.h"

#include "Enemy2BulletDieState.h"
class Enemy2BulletMovingState : public BulletState
{
public:
	Enemy2BulletMovingState(Enemy2BulletData *Enemy2BulletData);
    ~Enemy2BulletMovingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
	Enemy2BulletData *enemy2BulletData;
	
};

