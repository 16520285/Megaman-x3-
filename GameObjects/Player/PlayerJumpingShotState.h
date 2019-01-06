#pragma once
#include "Player.h"
#include "PlayerState.h"

class PlayerJumpingShotState : public PlayerState
{
public:
	PlayerJumpingShotState(PlayerData *playerData);
	~PlayerJumpingShotState();

	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorY;
	float acceleratorX;
	bool noPressed;
	bool allowMoveRight, allowMoveLeft;

};
