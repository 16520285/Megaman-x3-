
#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"
#include "Brick2Data.h"
#include "../../GameObjects/Entity.h"
#include "Brick2State.h"
#include "Brick2StandingState.h"



class Brick2 : public Entity {
public: Brick2();
		~Brick2();
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(Brick2State *newState);

		bool mCurrentReverse;

		void SetReverse(bool flag);

		Brick2State::StateName Brick2::getState();

		Brick2State::StateName mCurrentState;

		bool isOpen, isClose,isDeleted;

	    Entity *entity;

		int HP;
	
		
		

		

protected:
	Brick2Data *mBrick2Data;

	Animation *Brick2Die,
			  *Brick2Standing,	
		*CurrentAnimation;

	void changeAnimation(Brick2State::StateName state);
	//Animation *bullet;
	//ShotData *PlayerShot;

};