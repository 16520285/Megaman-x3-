#pragma once
#include"Boss3Data.h"
#include "Boss3State.h"

#include "Boss3PreparingState.h"

class Boss3FlyingState : public Boss3State
{
public:
	Boss3FlyingState(Boss3Data *Boss3Data);
	~Boss3FlyingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:

};

