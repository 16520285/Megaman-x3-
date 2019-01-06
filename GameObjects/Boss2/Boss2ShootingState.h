#pragma once
#include"Boss2Data.h"
#include "Boss2State.h"
#include "Boss2.h"

#include <math.h>

class Boss2ShootingState : public Boss2State
{
public:
	Boss2ShootingState(Boss2Data *Boss2Data);
	~Boss2ShootingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:


};

