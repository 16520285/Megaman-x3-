#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../../GameComponents/Animation.h"
#include "../../../GameComponents/GameGlobal.h"
#include "../../../GameComponents/Camera.h"

#include "Enemy3BulletData.h"
#include "../../Entity.h"
#include "../Bullet.h"
#include "Enemy3BulletMovingState.h"
#include "../BulletState.h"
class Enemy3Bullet : public Bullet {
public: Enemy3Bullet();
		~Enemy3Bullet();
		void Update(float dt);
		void SetState(BulletState *newState);
		Entity* getEntity();
	
protected:
	Enemy3BulletData *enemy3BulletData;
	
	

	
	
	
	//Animation *bullet;
	//ShotData *Enemy3Shot;

};