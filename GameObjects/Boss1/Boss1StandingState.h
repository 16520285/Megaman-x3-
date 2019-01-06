#pragma once
#include "Boss1State.h"
#include "Boss1Data.h"
#include "Boss1MovingState.h"
#include "Boss1MovingZiczacState.h"

class Boss1StandingState : public Boss1State
{
public:
	Boss1StandingState(Boss1Data *Boss1Data);
	~Boss1StandingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:

};

