#pragma once
#include "Enemy1.h"
#include "Enemy1State.h"

class Enemy1FallingState : public Enemy1State
{
public:
	Enemy1FallingState(EnemyData1 *playerData);
    ~Enemy1FallingState();

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

