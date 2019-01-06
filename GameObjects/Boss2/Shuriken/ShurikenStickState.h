#pragma once
#include"ShurikenData.h"
#include "ShurikenState.h"
#include "ShurikenDieState.h"
#include "Shuriken.h"

class ShurikenStickState : public ShurikenState
{
public:
	ShurikenStickState(ShurikenData *ShurikenData);
	~ShurikenStickState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:

};

