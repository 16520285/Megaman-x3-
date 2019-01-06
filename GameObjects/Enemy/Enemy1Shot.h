#pragma once
#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "Enemy1.h"
#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"
#include "EnemyData1.h"
#include "../Entity.h"

class Enemy1Shot : public Entity {
public: Enemy1Shot(Enemy1 *enemy1);
		~Enemy1Shot();
		enum MoveDirection
		{
			MoveToLeft, //chay tu phai sang trai
			MoveToRight, //chay tu trai sang phai
			None //dung im
		};
		void Update(float dt);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		bool mCurrentReverse;

		void SetReverse(bool flag);
	
		D3DXVECTOR3 GetEnemy1Position();
protected:
	Animation *bullet,
		*CurrentAnimation;
	D3DXVECTOR3 enemy1Position;
	//EnemyData *mEnemyData;
	//Animation *bullet;
	EnemyData1 *shotData;

};