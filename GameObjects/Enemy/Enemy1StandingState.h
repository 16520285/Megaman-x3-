#pragma once
#include "Enemy1State.h"
#include "EnemyData1.h"
#include "Enemy1JumpingState.h"
#include "Enemy1ShootingState.h"
class Enemy1StandingState : public Enemy1State
{
public:
	Enemy1StandingState(EnemyData1 *Enemy1Data);
    ~Enemy1StandingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

