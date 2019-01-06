#pragma once
#include "PlayerData.h"
#include "../Entity.h"
#include <map>

class PlayerState
{
public:
    enum StateName
    {
        Standing,
        Running,
        Falling,
        Jumping,
		Surfing,
		JumpingShot,
		RunningShot,
		StandingShot,
		ClimbingShot,
		Walling,
		SurfingShot,
		WallingShot,
		Hurting,
        Die
    };

    ~PlayerState();

    virtual void Update(float dt);

    virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

    //ham thuan ao bat buoc phai ke thua
    virtual StateName GetState() = 0;

protected:
    PlayerState(PlayerData *playerData);
    PlayerState();

    PlayerData *mPlayerData;
};

