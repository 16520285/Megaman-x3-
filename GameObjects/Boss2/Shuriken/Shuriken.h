#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../../GameComponents/Animation.h"
#include "../../../GameComponents/GameGlobal.h"
#include "../../Entity.h"
#include "ShurikenState.h"
#include "ShurikenData.h"
#include "ShurikenMovingState.h"
#include "ShurikenStickState.h"




class Shuriken : public Entity {
public: Shuriken();
		~Shuriken();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(ShurikenState *newState);

		bool mCurrentReverse;

		void SetReverse(bool flag);

		ShurikenState::StateName Shuriken::getState();

		ShurikenState::StateName mCurrentState;

		bool isLeft,isDeleted;	int count, time;

		void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);
		void GetPlayerPosition();

protected:
	ShurikenData *mShurikenData;

	Animation *ShurikenMoving,
		*ShurikenStick,
		*ShurikenDie,
		*CurrentAnimation;

	void changeAnimation(ShurikenState::StateName state);



};