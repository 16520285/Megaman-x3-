#pragma once
#include "BulletState.h"
#include "PlayerBulletData.h"

#include "PlayerBulletDieState.h"
class PlayerBulletMovingState : public BulletState
{
public:
	PlayerBulletMovingState(PlayerBulletData *PlayerBulletData);
    ~PlayerBulletMovingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
	PlayerBulletData *playerBulletData;
};

