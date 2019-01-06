#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"
#include "../Entity.h"
#include "Boss2Data.h"
#include "Boss2State.h"
#include "Boss2StandingState.h"
#include "../Player/Player.h"
#include "Shuriken/Shuriken.h"
#include "Boss2DieState.h"
class Boss2 : public Entity {
public: Boss2();
		~Boss2();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(Boss2State *newState);

		bool mCurrentReverse;

		void SetReverse(bool flag);

		Boss2State::StateName Boss2::getState();

		Boss2State::StateName mCurrentState;

		bool isLeft,isDestroyed,isDeleted;	int count, time,HP;

		void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);
		//void GetPlayerPosition();
		bool isRight();

		std::vector<Shuriken*>             mListBoss2Bullet;

		void onFired();

		void OnCollissionWithBullet(int damage);
protected:
	Boss2Data *mBoss2Data;

	Animation *Boss2Standing,
		*Boss2Attack,
		*Boss2Shooting,
		*Boss2Die,
		*CurrentAnimation;

	void changeAnimation(Boss2State::StateName state);

	//Animation *bullet;
	//ShotData *PlayerShot;
	


};