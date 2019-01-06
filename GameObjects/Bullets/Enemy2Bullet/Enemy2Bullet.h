#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../../GameComponents/Animation.h"
#include "../../../GameComponents/GameGlobal.h"
#include "../../../GameComponents/Camera.h"

#include "Enemy2BulletData.h"
#include "../../Entity.h"
#include "../Bullet.h"
#include "Enemy2BulletMovingState.h"
#include "../BulletState.h"
class Enemy2Bullet : public Bullet {
public: Enemy2Bullet();
		~Enemy2Bullet();
		void Update(float dt);
		void SetState(BulletState *newState);
		Entity* getEntity();
	
protected:
	Enemy2BulletData *enemy2BulletData;
	PlayerBulletData *a;
	

	
	
	
	//Animation *bullet;
	//ShotData *Enemy2Shot;

};