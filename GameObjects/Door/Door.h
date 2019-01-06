
#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"
#include "DoorData.h"
#include "../../GameObjects/Entity.h"
#include "DoorState.h"
#include "DoorOpenState.h"
#include "DoorCloseState.h"
#include "DoorStandingState.h"



class Door : public Entity {
public: Door();
		~Door();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(DoorState *newState);

		bool mCurrentReverse;

		void SetReverse(bool flag);

		DoorState::StateName Door::getState();

		DoorState::StateName mCurrentState;

		bool isOpen, isClose,locked,key;

	

		Entity *entity;

	
		
		

		

protected:
	DoorData *mDoorData;

	Animation *DoorOpen,
			  *DoorOpened,
			  *DoorClose,
			  *DoorClosed,
			  *DoorStanding,	
		*CurrentAnimation;

	void changeAnimation(DoorState::StateName state);
	//Animation *bullet;
	//ShotData *PlayerShot;

};