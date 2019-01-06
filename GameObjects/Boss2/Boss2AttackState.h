#pragma once
#include"Boss2Data.h"
#include "Boss2State.h"

#include <math.h>

class Boss2AttackState : public Boss2State
{
public:
	Boss2AttackState(Boss2Data *Boss2Data);
	~Boss2AttackState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat
	bool isLeft();
protected:
	bool _isLeft;
};

