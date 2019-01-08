#include "Boss3State.h"

#include "Boss3.h"
#include "Boss3ZiczacBeeState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss3GenerateBeeState::Boss3GenerateBeeState(Boss3Data *Boss3Data)
{
	
	this->mBoss3Data = Boss3Data;
	this->mBoss3Data->Boss3->SetVx(0);
	this->mBoss3Data->Boss3->SetVy(0);
	this->mBoss3Data->generateBee++;
	count = 0;
	clock = 50;
	
	this->mBoss3Data->attackTime2 +=3;
	this->mBoss3Data->Boss3->onFired();
}


Boss3GenerateBeeState::~Boss3GenerateBeeState()
{

}

void Boss3GenerateBeeState::Update(float dt)
{
	
	count++;
	if (count == clock) this->mBoss3Data->Boss3->SetState(new Boss3ZiczacBeeState(this->mBoss3Data));

	

}



Boss3State::StateName Boss3GenerateBeeState::GetState()
{
	return Boss3State::GenerateBee;
}

	