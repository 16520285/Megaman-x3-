#pragma once
#include "../BulletState.h"
#include "Enemy1BulletData.h"

#include "Enemy1BulletDieState.h"
class Enemy1BulletMovingState : public BulletState
{
public:
	Enemy1BulletMovingState(Enemy1BulletData *Enemy1BulletData);
    ~Enemy1BulletMovingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
	Enemy1BulletData *enemy1BulletData;
	
};

