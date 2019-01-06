#pragma once

#include "EnemyData2.h"
#include "Enemy2State.h"

#include "Enemy2ShootingState.h"
class Enemy2StandingState : public Enemy2State
{
public:
	Enemy2StandingState(EnemyData2 *Enemy1Data);
    ~Enemy2StandingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

