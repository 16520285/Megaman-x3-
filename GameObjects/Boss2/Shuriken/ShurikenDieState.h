#pragma once
#include"ShurikenData.h"
#include "ShurikenState.h"

#include "Shuriken.h"

class ShurikenDieState : public ShurikenState
{
public:
	ShurikenDieState(ShurikenData *ShurikenData);
	~ShurikenDieState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:

};

