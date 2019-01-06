#pragma once

#include "Brick2Data.h"
#include "Brick2State.h"


class Brick2DieState : public Brick2State
{
public:
	Brick2DieState(Brick2Data *Enemy1Data);
    ~Brick2DieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

