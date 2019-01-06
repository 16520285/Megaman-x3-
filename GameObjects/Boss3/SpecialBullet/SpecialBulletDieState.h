#pragma once
#include "SpecialBulletState.h"
#include "SpecialBulletData.h"


class SpecialBulletDieState : public SpecialBulletState
{
public:
	SpecialBulletDieState(SpecialBulletData *SpecialBulletData1);
    ~SpecialBulletDieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	int dem;
protected:
	//int count, time;
};

