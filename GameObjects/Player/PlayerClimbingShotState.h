#pragma once
#include "PlayerState.h"

class PlayerClimbingShotState : public PlayerState
{
public:
    PlayerClimbingShotState(PlayerData *playerData);
    ~PlayerClimbingShotState();

    void Update(float dt);

    void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState(); // lay state nhan vat

protected:
};

