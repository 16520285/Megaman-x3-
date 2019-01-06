#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"

#include "Enemy3Data.h"
#include "../Entity.h"
#include "Enemy3StandingState.h"
#include "Enemy3DieState.h"
#include "../Bullets/Enemy3Bullet/Enemy3Bullet.h"
class Enemy3 : public Entity {
public: Enemy3();
		~Enemy3();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(Enemy3State *newState);

		bool mCurrentReverse;
		
		void SetReverse(bool flag);
		
		Enemy3State::StateName Enemy3::getState();

		Enemy3State::StateName mCurrentState;

		bool isLeft,isDestroyed,isDeleted;

		void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);

		void OnCollissionWithBullet(int damage);
	
		Entity* getEntity();

		int HP;

		void onFired();

		std::vector<Enemy3Bullet*>             mListEnemy3Bullet;
protected:
	Enemy3Data *mEnemyData3;

	Animation *Enemy3Standing,
			  *Enemy3Flying,
			  *Enemy3Falling,
			  *Enemy3Shooting,	
			  *Enemy3Die,	
			  *CurrentAnimation;
	
	void changeAnimation(Enemy3State::StateName state);
	//Animation *bullet;
	//ShotData *PlayerShot;

};