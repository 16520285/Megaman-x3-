#pragma once

#include "DoorData.h"
#include "DoorState.h"


class DoorClosedState : public DoorState
{
public:
	DoorClosedState(DoorData *Enemy1Data);
    ~DoorClosedState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
	//int count, time;
};

