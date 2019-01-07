#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../../GameComponents/Animation.h"
#include "../../../GameComponents/GameGlobal.h"
#include "../../Entity.h"
#include "SpecialBulletState.h"
#include "SpecialBulletData.h"
#include "SpecialBulletFlyingState.h"
#include "SpecialBulletDieState.h"


class SpecialBullet : public Entity {
public: SpecialBullet();
		~SpecialBullet();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(SpecialBulletState *newState);

		bool mCurrentReverse;

		void SetReverse(bool flag);

		SpecialBulletState::StateName SpecialBullet::getState();

		SpecialBulletState::StateName mCurrentState;

		bool isLeft,isDestroyed,isDeleted,isFollowing,isBegin;	int count, time,HP;

		void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);
		void GetPlayerPosition();
		
protected:
	SpecialBulletData *mSpecialBulletData;

	Animation *SpecialBulletFlying,
			  *SpecialBulletDie, 	
		*CurrentAnimation;

	void changeAnimation(SpecialBulletState::StateName state);



};