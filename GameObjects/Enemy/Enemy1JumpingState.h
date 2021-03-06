#pragma once
#include "Enemy1.h"
#include "Enemy1State.h"
#include "Enemy1FallingState.h"
class Enemy1JumpingState : public Enemy1State
{
public:
	Enemy1JumpingState(EnemyData1 *playerData);
    ~Enemy1JumpingState();

    void Update(float dt);

    //void HandleKeyboard(std::map<int, bool> keys);

	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

    virtual StateName GetState();

protected:
    //do bien tien van toc sau moi frame tinh bang pixel / s
    float acceleratorY;
    float acceleratorX;
    bool noPressed;
    bool allowMoveRight, allowMoveLeft;
};

