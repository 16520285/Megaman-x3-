#pragma once
#include "DoorState.h"
#include "DoorData.h"
#include "DoorClosedState.h"

class DoorCloseState : public DoorState
{
public:
	DoorCloseState(DoorData *DoorData);
    ~DoorCloseState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	int dem;
protected:
	//int count, time;
};

