#pragma once
#include "Boss1State.h"
#include "Boss1Data.h"


class Boss1DieState : public Boss1State
{
public:
	Boss1DieState(Boss1Data *Boss1Data1);
    ~Boss1DieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	int dem;
protected:
	//int count, time;
};

