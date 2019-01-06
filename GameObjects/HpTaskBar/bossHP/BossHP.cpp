#include "BossHP.h"
#include <iostream>
#include <string>
#include "../../../GameComponents/GameLog.h"
BossHP::BossHP()
{
	
	CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile032.png", 1, 1, 1, 0.0f);


	
}
void BossHP::Update(float dt,int hp)
{
	switch (hp)
	{
	case 0:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile000.png", 1, 1, 1, 0.0f);
		break;
	case 1:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile001.png", 1, 1, 1, 0.0f);
		break;
	case 2:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile002.png", 1, 1, 1, 0.0f);
		break;
	case 3:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile003.png", 1, 1, 1, 0.0f);
		break;
	case 4:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile004.png", 1, 1, 1, 0.0f);
		break;
	case 5:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile005.png", 1, 1, 1, 0.0f);
		break;
	case 6:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile006.png", 1, 1, 1, 0.0f);
		break;
	case 7:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile007.png", 1, 1, 1, 0.0f);
		break;
	case 8:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile008.png", 1, 1, 1, 0.0f);
		break;
	case 9:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile009.png", 1, 1, 1, 0.0f);
		break;
	case 10:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile010.png", 1, 1, 1, 0.0f);
		break;
	case 11:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile011.png", 1, 1, 1, 0.0f);
		break;
	case 12:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile012.png", 1, 1, 1, 0.0f);
		break;
	case 13:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile013.png", 1, 1, 1, 0.0f);
		break;
	case 14:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile014.png", 1, 1, 1, 0.0f);
		break;
	case 15:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile015.png", 1, 1, 1, 0.0f);
		break;
	case 16:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile016.png", 1, 1, 1, 0.0f);
		break;
	case 17:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile017.png", 1, 1, 1, 0.0f);
		break;
	case 18:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile018.png", 1, 1, 1, 0.0f);
		break;
	case 19:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile019.png", 1, 1, 1, 0.0f);
		break;
	case 20:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile020.png", 1, 1, 1, 0.0f);
		break;
	case 21:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile021.png", 1, 1, 1, 0.0f);
		break;
	case 22:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile022.png", 1, 1, 1, 0.0f);
		break;
	case 23:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile023.png", 1, 1, 1, 0.0f);
		break;
	case 24:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile024.png", 1, 1, 1, 0.0f);
		break;
	case 25:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile025.png", 1, 1, 1, 0.0f);
		break;
	case 26:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile026.png", 1, 1, 1, 0.0f);
		break;
	case 27:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile027.png", 1, 1, 1, 0.0f);
		break;
	case 28:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile028.png", 1, 1, 1, 0.0f);
		break;
	case 29:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile029.png", 1, 1, 1, 0.0f);
		break;
	case 30:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile030.png", 1, 1, 1, 0.0f);
		break;
	case 31:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile031.png", 1, 1, 1, 0.0f);
		break;
	case 32:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile032.png", 1, 1, 1, 0.0f);
		break;
	default:
		CurrentAnimation = new Animation("Resources/HPTaskBar/bossHP/tile000.png", 1, 1, 1, 0.0f);
		break;
	}

	
	
	
	
	//CurrentAnimation = new Animation("Resources/BossHP"+HP, 1, 1, 1, 0.0f);
	
	
}


void BossHP::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	
	//CurrentAnimation->SetPosition(this->GetPosition());
	//CurrentAnimation->SetPosition(D3DXVECTOR3(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2, 0));

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(D3DXVECTOR3(GameGlobal::GetWidth() / 2+400, GameGlobal::GetHeight() / 2-270, 0));
}
