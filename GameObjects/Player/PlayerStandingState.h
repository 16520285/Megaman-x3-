#pragma once
#include "PlayerState.h"
#include "PlayerStandingShotState.h"
class PlayerStandingState : public PlayerState
{
public:
    PlayerStandingState(PlayerData *playerData);
    ~PlayerStandingState();

    void Update(float dt);

    void HandleKeyboard(std::map<int, bool> keys);

	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

    virtual StateName GetState(); // lay state nhan vat

protected:
};

