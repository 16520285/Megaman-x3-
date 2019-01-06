#include "HpTaskBar.h"
#include <iostream>
#include <string>
#include "../../GameComponents/GameLog.h"
HpTaskBar::HpTaskBar()
{
	
	CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar16.png", 1, 1, 1, 0.0f);

	
}
void HpTaskBar::Update(float dt,int hp)
{
	switch (hp)
	{
	case 16:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar16.png", 1, 1, 1, 0.0f);
		break;
	case 14:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar14.png", 1, 1, 1, 0.0f);
		break;
	case 12:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar12.png", 1, 1, 1, 0.0f);
		break;
	case 10:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar10.png", 1, 1, 1, 0.0f);
		break;
	case 8:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar08.png", 1, 1, 1, 0.0f);
		break;
	case 6:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar06.png", 1, 1, 1, 0.0f);
		break;
	case 4:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar04.png", 1, 1, 1, 0.0f);
		break;
	case 2:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar02.png", 1, 1, 1, 0.0f);
		break;
	case 0:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar00.png", 1, 1, 1, 0.0f);
		break;
	default:
		CurrentAnimation = new Animation("Resources/HpTaskBar/HpTaskBar00.png", 1, 1, 1, 0.0f);
		break;
	}
	
	
	
	
	//CurrentAnimation = new Animation("Resources/HpTaskBar"+HP, 1, 1, 1, 0.0f);
	
	
}


void HpTaskBar::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	
	//CurrentAnimation->SetPosition(this->GetPosition());
	//CurrentAnimation->SetPosition(D3DXVECTOR3(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2, 0));

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(D3DXVECTOR3(GameGlobal::GetWidth() / 2-400, GameGlobal::GetHeight() / 2-270, 0));
}
