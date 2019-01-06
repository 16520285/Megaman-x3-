#pragma once
#include "Boss2State.h"
#include "Boss2Data.h"


class Boss2DieState : public Boss2State
{
public:
	Boss2DieState(Boss2Data *Boss2Data1);
    ~Boss2DieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	int dem;
protected:
	//int count, time;
};

