#pragma once
#include"Boss3Data.h"
#include "Boss3State.h"
#include "Boss3AttackState.h"

class Boss3PreparingState : public Boss3State
{
public:
	Boss3PreparingState(Boss3Data *Boss3Data);
	~Boss3PreparingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

	
protected:

};

