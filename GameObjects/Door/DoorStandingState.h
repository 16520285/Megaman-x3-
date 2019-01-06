#pragma once

#include "DoorData.h"
#include "DoorState.h"


class DoorStandingState : public DoorState
{
public:
	DoorStandingState(DoorData *Enemy1Data);
    ~DoorStandingState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

