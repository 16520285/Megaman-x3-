#pragma once
#include "PlayerState.h"
#include "Player.h"
#include "PlayerClimbingShotState.h"
class PlayerClimbingState : public PlayerState
{
public:
	PlayerClimbingState(PlayerData *playerData);
	~PlayerClimbingState();

	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorX;
	float acceleratorY;
};

