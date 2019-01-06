#include "Brick2DieState.h"


#include "Brick2.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
#include "../../GameComponents/Sound.h"
Brick2DieState::Brick2DieState(Brick2Data *playerData)
{
	this->mBrick2Data = playerData;
	count = 0;
	Sound::getInstance()->play("Explosion", false, 1);
}


Brick2DieState::~Brick2DieState()
{
}

void Brick2DieState::Update(float dt)
{
	count++;
	if (count == 10) this->mBrick2Data->Brick2->isDeleted = true;
	
	

	
}



Brick2State::StateName Brick2DieState::GetState()
{
	return Brick2State::Die;
}
