#pragma once
#include "Enemy1State.h"
#include "EnemyData1.h"


class EnemyDieState : public Enemy1State
{
public:
	EnemyDieState(EnemyData1 *EnemyData1);
    ~EnemyDieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	int dem;
protected:
	//int count, time;
};

