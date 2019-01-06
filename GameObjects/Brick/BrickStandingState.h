#pragma once

#include "BrickData.h"
#include "BrickState.h"
#include "BrickDieState.h"

class BrickStandingState : public BrickState
{
public:
	BrickStandingState(BrickData *Enemy1Data);
    ~BrickStandingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

