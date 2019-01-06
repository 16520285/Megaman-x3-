#pragma once
#include"Boss3Data.h"
#include "Boss3State.h"

#include "Boss3PreparingState.h"
#include "Boss3GenerateBeeState.h"
#include "Boss3StandingState.h"
class Boss3BornState : public Boss3State
{
public:
	Boss3BornState(Boss3Data *Boss3Data);
	~Boss3BornState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:

};

