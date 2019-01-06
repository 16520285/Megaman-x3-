#pragma once
#include"Boss3Data.h"
#include "Boss3State.h"

#include "Boss3PreparingState.h"
#include "Boss3ZiczacBeeState.h"
class Boss3StandingState : public Boss3State
{
public:
	Boss3StandingState(Boss3Data *Boss3Data);
	~Boss3StandingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

private:
	int random;

};

