#pragma once
#pragma once

#include <d3d9.h>
#include <d3dx9.h>


#include "../../../GameComponents/Animation.h"
#include "../../../GameComponents/GameGlobal.h"
#include "../../../GameComponents/Camera.h"

#include "../../../GameObjects/Entity.h"
class BossHP : public Entity {
public: BossHP();
		


		
		void Update(float dt,int hp);

		void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

		bool isDraw;
		


protected:
	Animation		*CurrentAnimation;
	int HP;

};