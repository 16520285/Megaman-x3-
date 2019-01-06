#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"
#include "../Entity.h"
#include "PlayerData.h"
#include "PlayerState.h"
#include "PlayerRunningState.h"
#include "PlayerFallingState.h"
#include "PlayerHurtingState .h"
#include "../Bullets/PlayerBullet.h"
#include "PlayerDieState.h"

class Player : public Entity
{
public:
    Player();
    ~Player();

    enum MoveDirection
    {
        MoveToLeft, //chay tu phai sang trai
        MoveToRight, //chay tu trai sang phai
        None //dung im
    };

    void Update(float dt);

    void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

    void SetState(PlayerState *newState);

    MoveDirection getMoveDirection();

    RECT GetBound();     

    PlayerState::StateName Player::getState();

 
    void HandleKeyboard(std::map<int, bool> keys);

    void OnKeyPressed(int key);

    void OnKeyUp(int key);

    //true thi se lat nguoc anh theo truc y
    void SetReverse(bool flag);

	bool allowJump, mCurrentReverse, allowShot, allowJumpingShot;

	bool allowMoveLeft;
	bool allowMoveRight;

	void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);
	void OnCollisionWithEnemy();
	void OnNoCollisionWithBottom();
	void FindFollowAnimation();
	PlayerState::StateName mCurrentState;

	std::vector<PlayerBullet*>             mListPlayerBullet;

	void OnFired(int _level);

	int count,level=1,clock=0,HP;

	bool charging,nobody;
protected:
    PlayerData *mPlayerData;

	Animation   *CurrentAnimation,
		*FollowAnimation,
		*playerStanding,
		*playerRunning,
		*playerJumping,
		*playerSurfing,
		*playerSurfingShot,
		*playerRunningShot,
		*playerJumpingShot,
		*playerStandingShot,
		*playerClimbingShot,
		*playerWalling,
		*playerWallingShot,
		*playerFalling,
		*playerHurting,
		*playerDie,
		*charged1,
		*charged2
		;

    void changeAnimation(PlayerState::StateName state);

   // PlayerState::StateName mCurrentState;

    //chi cho phep jump khi nhan nhim space, muon nhay lai phai tha phim space roi nhan lai
    
};

