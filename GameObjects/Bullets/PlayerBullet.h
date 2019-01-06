#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"

#include "PlayerBulletData.h"
#include "../Entity.h"
#include "Bullet.h"
#include "PlayerBulletMovingState.h"
class PlayerBullet : public Bullet {
public: PlayerBullet();
		~PlayerBullet();
		PlayerBullet(int level);
		void Update(float dt);
		void SetState(BulletState *newState);
		
	
protected:
	PlayerBulletData *playerBulletData;

	
	
	
	//Animation *bullet;
	//ShotData *PlayerShot;

};