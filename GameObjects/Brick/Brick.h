
#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"
#include "BrickData.h"
#include "../../GameObjects/Entity.h"
#include "BrickState.h"
#include "BrickStandingState.h"



class Brick : public Entity {
public: Brick();
		~Brick();
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		void SetState(BrickState *newState);

		bool mCurrentReverse;

		void SetReverse(bool flag);

		BrickState::StateName Brick::getState();

		BrickState::StateName mCurrentState;

		bool isOpen, isClose,isDeleted;

	    Entity* getEntity();

		int HP;
	
		
		

		

protected:
	BrickData *mBrickData;

	Animation *BrickDie,
			  *BrickStanding,	
		*CurrentAnimation;

	void changeAnimation(BrickState::StateName state);
	//Animation *bullet;
	//ShotData *PlayerShot;

};