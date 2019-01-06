#pragma once
#include "PlayerState.h"
#include "PlayerStandingState.h"
class PlayerHurtingState : public PlayerState
{
public:
    PlayerHurtingState(PlayerData *playerData);
    ~PlayerHurtingState();

    void Update(float dt);

    void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

	bool isHurting;
	int count, timeHurting;

protected:
};

