#pragma once
#include "Enemy2State.h"
#include "EnemyData2.h"


class Enemy2DieState : public Enemy2State
{
public:
	Enemy2DieState(EnemyData2 *EnemyData2);
    ~Enemy2DieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	int dem;
protected:
	//int count, time;
};

