#pragma once
#include "Boss1State.h"
#include "Boss1Data.h"
#include "Boss1BornState.h"
#include "Boss1HorizontalState.h"
#include "Boss1MovingState.h"
#include "Boss1StandingState.h"

class Boss1MovingZiczacState : public Boss1State
{
public:
	Boss1MovingZiczacState(Boss1Data *Boss1Data);
	~Boss1MovingZiczacState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:
	
	

};

