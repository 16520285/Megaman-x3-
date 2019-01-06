#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"

#include "PlayerBulletData.h"
#include "../Entity.h"
//#include "BulletStandingState.h"
#include "BulletState.h"
class Bullet : public Entity {
public: Bullet();
		~Bullet();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		
		virtual void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		virtual void SetState(BulletState *newState);

		bool mCurrentReverse;
		
		void SetReverse(bool flag);
		
		BulletState::StateName Bullet::getState();

		BulletState::StateName mCurrentState;

		bool isLeft;

		void OnCollision();
	
		bool isDestroyed,isDeleted;

		int damage;
protected:
	//BulletData *mEnemyData3;

	Animation *BulletMoving,
			  *BulletDie,	
			  *CurrentAnimation;
	
	void changeAnimation(BulletState::StateName state);
	//Animation *bullet;
	//ShotData *PlayerShot;

};