#pragma once
#include "../BulletState.h"
#include "Enemy3BulletData.h"

#include "Enemy3BulletDieState.h"
class Enemy3BulletMovingState : public BulletState
{
public:
	Enemy3BulletMovingState(Enemy3BulletData *Enemy3BulletData);
    ~Enemy3BulletMovingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
	Enemy3BulletData *enemy3BulletData;
	
};

