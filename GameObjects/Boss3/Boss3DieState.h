#pragma once
#include "Boss3State.h"
#include "Boss3Data.h"


class Boss3DieState : public Boss3State
{
public:
	Boss3DieState(Boss3Data *Boss3Data1);
    ~Boss3DieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	int dem;
protected:
	//int count, time;
};

