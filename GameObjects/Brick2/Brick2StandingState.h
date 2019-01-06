#pragma once

#include "Brick2Data.h"
#include "Brick2State.h"
#include "Brick2DieState.h"

class Brick2StandingState : public Brick2State
{
public:
	Brick2StandingState(Brick2Data *Enemy1Data);
    ~Brick2StandingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

