#pragma once
#include "BeeState.h"
#include "BeeData.h"


class BeeDieState : public BeeState
{
public:
	BeeDieState(BeeData *BeeData1);
    ~BeeDieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	int dem;
protected:
	//int count, time;
};

