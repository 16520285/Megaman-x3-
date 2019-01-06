#pragma once
#include"SpecialBulletData.h"
#include "SpecialBulletState.h"

#include "SpecialBullet.h"

class SpecialBulletFlyingState : public SpecialBulletState
{
public:
	SpecialBulletFlyingState(SpecialBulletData *SpecialBulletData);
	~SpecialBulletFlyingState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:

};

