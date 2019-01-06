#pragma once
#include "../BulletState.h"
#include "Enemy2BulletData.h"

#include "Enemy2BulletMovingState.h"
class Enemy2BulletDieState : public BulletState
{
public:
	Enemy2BulletDieState(Enemy2BulletData *Enemy2BulletData);
    ~Enemy2BulletDieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
	Enemy2BulletData *enemy2BulletData;
};

