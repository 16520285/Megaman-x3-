#pragma once
#include"ShurikenData.h"
#include "ShurikenState.h"

#include "Shuriken.h"

class ShurikenMovingState : public ShurikenState
{
public:
	ShurikenMovingState(ShurikenData *ShurikenData);
	~ShurikenMovingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:

};

