#pragma once
#include "../BulletState.h"
#include "Enemy3BulletData.h"

#include "Enemy3BulletMovingState.h"
class Enemy3BulletDieState : public BulletState
{
public:
	Enemy3BulletDieState(Enemy3BulletData *Enemy3BulletData);
    ~Enemy3BulletDieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
	Enemy3BulletData *enemy3BulletData;
};

