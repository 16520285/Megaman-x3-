#include "Boss3State.h"
#include "Boss3FlyingState.h"
#include "Boss3.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss3FlyingState::Boss3FlyingState(Boss3Data *Boss3Data)
{
	this->mBoss3Data = Boss3Data;
	this->mBoss3Data->Boss3->SetVx(0);
	this->mBoss3Data->Boss3->SetVy(0);
	count = 0;
	clock = 200;
}


Boss3FlyingState::~Boss3FlyingState()
{

}

void Boss3FlyingState::Update(float dt)
{
	count++;
	if (count == clock)
		this->mBoss3Data->Boss3->SetState(new Boss3PreparingState(this->mBoss3Data));
	
}



Boss3State::StateName Boss3FlyingState::GetState()
{
	return Boss3State::Flying;
}

