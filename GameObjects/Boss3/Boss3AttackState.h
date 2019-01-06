#pragma once
#include"Boss3Data.h"
#include "Boss3State.h"
#include "Boss3GenerateBeeState.h"
#include <math.h>
#include "Boss3PreparingState.h"

class Boss3AttackState : public Boss3State
{
public:
	Boss3AttackState(Boss3Data *Boss3Data);
	~Boss3AttackState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat
	void ReturnPointLeft();
	void ReturnPointRight();
	bool isTurn;
	void OnAttack();
protected:
	float playerPosX, playerPosY;
	float distanceX, distanceY, acceX;
	
};

