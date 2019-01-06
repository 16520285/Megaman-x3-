#pragma once
#include "Enemy3State.h"

#include "Enemy3Data.h"


class Enemy3DieState : public Enemy3State
{
public:
	Enemy3DieState(Enemy3Data *EnemyData3);
    ~Enemy3DieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	int dem;
protected:
	//int count, time;
};

