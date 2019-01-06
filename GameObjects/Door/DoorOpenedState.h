#pragma once

#include "DoorData.h"
#include "DoorState.h"


class DoorOpenedState : public DoorState
{
public:
	DoorOpenedState(DoorData *Enemy1Data);
    ~DoorOpenedState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

