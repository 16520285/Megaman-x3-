#pragma once
#include <d3d9.h>
#include <d3dx9.h>


#include "../../../GameComponents/Animation.h"
#include "../../../GameComponents/GameGlobal.h"
#include "../../../GameComponents/Camera.h"

#include "Enemy1BulletData.h"
#include "../../Entity.h"
#include "../Bullet.h"
#include "Enemy1BulletMovingState.h"
#include "../BulletState.h"
class Enemy1Bullet : public Bullet {
public: Enemy1Bullet();
		~Enemy1Bullet();
		void Update(float dt);
		void SetState(BulletState *newState);
		Entity* getEntity();
	
protected:
	Enemy1BulletData *enemy1BulletData;
	PlayerBulletData *a;
	

	
	
	
	//Animation *bullet;
	//ShotData *Enemy1Shot;

};