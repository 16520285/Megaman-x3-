#pragma once
#include "Boss1State.h"
#include "Boss1Data.h"
#include "Boss1StandingState.h"
#include "Boss1HorizontalState.h"
#include "Boss1MovingZiczacState.h"

class Boss1BornState : public Boss1State
{
public:
	Boss1BornState(Boss1Data *Boss1Data);
	~Boss1BornState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:

};

