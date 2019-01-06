#pragma once
#include "Enemy3.h"
#include "Enemy3State.h"

class Enemy3FlyingState : public Enemy3State
{
public:
	Enemy3FlyingState(Enemy3Data *playerData);
    ~Enemy3FlyingState();

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

