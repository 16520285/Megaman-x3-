#pragma once
#include "Enemy3.h"
#include "Enemy3State.h"
//#include "Enemy3FallingState.h"
class Enemy3ShootingState : public Enemy3State
{
public:
	Enemy3ShootingState(Enemy3Data *playerData);
    ~Enemy3ShootingState();

    void Update(float dt);

    //void HandleKeyboard(std::map<int, bool> keys);

	//void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

    virtual StateName GetState();

protected:
    //do bien tien van toc sau moi frame tinh bang pixel / s
    float acceleratorY;
    float acceleratorX;
    bool noPressed;
    bool allowMoveRight, allowMoveLeft;
};

