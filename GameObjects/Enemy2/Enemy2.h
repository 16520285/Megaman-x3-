
#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"
#include "EnemyData2.h"
#include "../../GameObjects/Entity.h"
#include "Enemy2State.h"
#include "Enemy2ShootingState.h"
#include "Enemy2StandingState.h"
#include "Enemy2DieState.h"
#include "../Bullets/Enemy2Bullet/Enemy2Bullet.h"

class Enemy2 : public Entity {
public: Enemy2();
		~Enemy2();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(Enemy2State *newState);

		bool mCurrentReverse;

		void SetReverse(bool flag);

		Enemy2State::StateName Enemy2::getState();

		Enemy2State::StateName mCurrentState;

		bool isLeft, isDestroyed, isDeleted;

		void OnCollissionWithBullet(int damage);

		Entity* getEntity();

		int HP;
		
		void onFired();

		std::vector<Enemy2Bullet*>             mListEnemy2Bullet;

protected:
	EnemyData2 *mEnemyData2;

	Animation *Enemy2Standing,
		*Enemy2Shooting,
		*Enemy2Die,
		*CurrentAnimation;

	void changeAnimation(Enemy2State::StateName state);
	//Animation *bullet;
	//ShotData *PlayerShot;

};