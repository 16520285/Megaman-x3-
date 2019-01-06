#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"

#include "Boss1Data.h"
#include "../Entity.h"
#include "Boss1State.h"
#include "Boss1MovingState.h"
#include "Boss1StandingState.h"
#include "Boss1BornState.h"
#include "Boss1DieState.h"

class Boss1 : public Entity {
public: Boss1();
		~Boss1();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(Boss1State *newState);

		bool mCurrentReverse;

		void SetReverse(bool flag);

		Boss1State::StateName Boss1::getState();

		Boss1State::StateName mCurrentState;

		bool isLeft,isDeleted,isDestroyed;	int count, time,HP;

		void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);

		void OnCollissionWithBullet(int damage);
protected:
	Boss1Data *mBoss1Data;

	Animation *Boss1Standing,
		*Boss1Moving,
		*Boss1Born,
		*Boss1Die,
		*Boss1Horizontal,
		*CurrentAnimation;

	void changeAnimation(Boss1State::StateName state);

	//Animation *bullet;
	//ShotData *PlayerShot;

};