#include "Boss3State.h"
#include "Boss3StandingState.h"
#include "Boss3.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
#include <cstdlib>
#include <ctime>
Boss3StandingState::Boss3StandingState(Boss3Data *Boss3Data)
{
	this->mBoss3Data = Boss3Data;
	this->mBoss3Data->Boss3->SetVx(0);
	this->mBoss3Data->Boss3->SetVy(0);
	count = 0;
	clock = 70;
	
	//GAMELOG("a:%d", random);
}


Boss3StandingState::~Boss3StandingState()
{

}

void Boss3StandingState::Update(float dt)
{
	count++; 
	if (count == clock) this->mBoss3Data->Boss3->SetState(new Boss3PreparingState(this->mBoss3Data));
	
	
}



Boss3State::StateName Boss3StandingState::GetState()
{
	return Boss3State::Standing;
}

