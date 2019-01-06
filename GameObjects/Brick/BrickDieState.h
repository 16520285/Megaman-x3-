#pragma once

#include "BrickData.h"
#include "BrickState.h"


class BrickDieState : public BrickState
{
public:
	BrickDieState(BrickData *Enemy1Data);
    ~BrickDieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

