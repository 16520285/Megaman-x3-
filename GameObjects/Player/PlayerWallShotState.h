#pragma once
#include "Player.h"
#include "PlayerState.h"

class PlayerWallShotState : public PlayerState
{
public:
    PlayerWallShotState(PlayerData *playerData);
    ~PlayerWallShotState();

    void Update(float dt);

    void HandleKeyboard(std::map<int, bool> keys);

	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

    virtual StateName GetState();

protected:
    //do bien tien van toc sau moi frame tinh bang pixel / s
    float acceleratorY;
    float acceleratorX;
    bool noPressed;
    bool allowMoveRight, allowMoveLeft;
};

