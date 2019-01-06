#pragma once
#include"BeeData.h"
#include "BeeState.h"

#include "Bee.h"

class BeeFlyingState : public BeeState
{
public:
	BeeFlyingState(BeeData *BeeData);
	~BeeFlyingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:

};

