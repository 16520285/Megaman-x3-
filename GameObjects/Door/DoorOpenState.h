#pragma once

#include "DoorData.h"
#include "DoorState.h"
#include "DoorOpenedState.h"

class DoorOpenState : public DoorState
{
public:
	DoorOpenState(DoorData *Enemy1Data);
    ~DoorOpenState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

