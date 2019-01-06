#pragma once
#include "PlayerState.h"
#include "PlayerData.h"


class PlayerDieState : public PlayerState
{
public:
	PlayerDieState(PlayerData *PlayerData1);
    ~PlayerDieState();

    void Update(float dt);

   // void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	
protected:
	//int count, time;
};

