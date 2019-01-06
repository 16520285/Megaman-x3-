#pragma once
#include"Boss3Data.h"
#include "Boss3State.h"
#include "../../GameComponents/Animation.h"
#include "Boss3BornState.h"
class Boss3GenerateBeeState : public Boss3State
{
public:
	Boss3GenerateBeeState(Boss3Data *Boss3Data);
	~Boss3GenerateBeeState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:
	
};

