#pragma once
#include "Boss1State.h"
#include "Boss1Data.h"
#include "Boss1StandingState.h"
#include "Boss1MovingZiczacState.h"
#include "Boss1HorizontalState.h"

class Boss1MovingState : public Boss1State
{
public:
	Boss1MovingState(Boss1Data *Boss1Data);
	~Boss1MovingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:
	
};

