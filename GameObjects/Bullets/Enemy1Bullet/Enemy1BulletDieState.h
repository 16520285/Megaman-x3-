#pragma once
#include "../BulletState.h"
#include "Enemy1BulletData.h"

#include "Enemy1BulletMovingState.h"
class Enemy1BulletDieState : public BulletState
{
public:
	Enemy1BulletDieState(Enemy1BulletData *Enemy1BulletData);
    ~Enemy1BulletDieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
	Enemy1BulletData *enemy1BulletData;
};

