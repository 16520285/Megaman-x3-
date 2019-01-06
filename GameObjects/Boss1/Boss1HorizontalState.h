#pragma once
#include "Boss1State.h"
#include "Boss1Data.h"
#include "Boss1BornState.h"
#include "Boss1MovingZiczacState.h"

class Boss1HorizontalState : public Boss1State
{
public:
	Boss1HorizontalState(Boss1Data *Boss1Data);
	~Boss1HorizontalState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:
	int count, time;
};

