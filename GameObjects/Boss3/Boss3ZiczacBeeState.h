#pragma once
#include"Boss3Data.h"
#include "Boss3State.h"
#include "../../GameComponents/Animation.h"

class Boss3ZiczacBeeState : public Boss3State
{
public:
	Boss3ZiczacBeeState(Boss3Data *Boss3Data);
	~Boss3ZiczacBeeState();

	void Update(float dt);

	// void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState(); // lay state nhan vat

protected:
	bool isDown;
	bool isLeft;
	int count2;
};

