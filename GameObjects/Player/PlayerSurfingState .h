#pragma once
#include "PlayerState.h"
#include "Player.h"

class PlayerSurfingState : public PlayerState
{
public:
	PlayerSurfingState(PlayerData *playerData);
	~PlayerSurfingState();

	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);
protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorX;
};

