#pragma once
#include "Enemy3State.h"
#include "Enemy3Data.h"
#include "Enemy3FlyingState.h"
#include "Enemy3ShootingState.h"
class Enemy3StandingState : public Enemy3State
{
public:
	Enemy3StandingState(Enemy3Data *Enemy3Data);
    ~Enemy3StandingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

