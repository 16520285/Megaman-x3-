#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"

#include "Boss3Data.h"
#include "../Entity.h"
#include "Boss3State.h"
#include "Boss3FlyingState.h"
#include "Boss3AttackState.h"
#include "Boss3GenerateBeeState.h"
#include "../Player/Player.h"
#include "Bee/Bee.h"
#include "Boss3DieState.h"
#include "SpecialBullet/SpecialBullet.h"
class Boss3 : public Entity {
public: Boss3(Player *player);
		~Boss3();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(Boss3State *newState);

		bool mCurrentReverse;

		void SetReverse(bool flag);

		Boss3State::StateName Boss3::getState();

		Boss3State::StateName mCurrentState;

		bool isLeft,isDestroyed,isDeleted;	int count, time,HP;

		void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);
		void GetPlayerPosition();
		bool OnRight();
		void OnCollissionWithBullet(int damage);
		void onFired();
		std::vector<Bee*>             mListBee;
		
protected:
	Boss3Data *mBoss3Data;

	Animation *Boss3Flying,
		*Boss3GenerateBee,
		*Boss3Attack,
		*Boss3Preparing,
		*Boss3Die,
		*Boss3ZiczacBee,
		*Wings,
		*Boss3Standing,
		*CurrentAnimation;

	void changeAnimation(Boss3State::StateName state);
	int wingsDistance = 75;
	//Animation *bullet;
	//ShotData *PlayerShot;
	Player *player;
	Bee *bee;
	bool onRight;
	

};