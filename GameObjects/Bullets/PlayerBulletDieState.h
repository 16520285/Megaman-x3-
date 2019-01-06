#pragma once
#include "BulletState.h"
#include "PlayerBulletData.h"

#include "PlayerBulletMovingState.h"
class PlayerBulletDieState : public BulletState
{
public:
	PlayerBulletDieState(PlayerBulletData *PlayerBulletData);
    ~PlayerBulletDieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
	PlayerBulletData *playerBulletData;
};

