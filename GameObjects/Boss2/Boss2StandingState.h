#pragma once
#include"Boss2Data.h"
#include "Boss2State.h"
#include "Boss2.h"

#include <math.h>

class Boss2StandingState : public Boss2State
{
public:
	Boss2StandingState(Boss2Data *Boss2Data);
	~Boss2StandingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:
	
	
};

