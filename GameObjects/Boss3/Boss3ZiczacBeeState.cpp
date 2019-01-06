#include "Boss3State.h"
#include "Boss3ZiczacBeeState.h"
#include "Boss3.h"

#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss3ZiczacBeeState::Boss3ZiczacBeeState(Boss3Data *Boss3Data)
{

	this->mBoss3Data = Boss3Data;

	//this->mBoss3Data->Boss3->SetVy(-300.0f);
	count = 0;
	clock = 300;
	count2 = 0;
	isDown = true;
	isLeft = false;
	
	
}


Boss3ZiczacBeeState::~Boss3ZiczacBeeState()
{

}

void Boss3ZiczacBeeState::Update(float dt)
{
	
	if (this->mBoss3Data->Boss3->GetPosition().x <= 19509.3 - 420)
	{

		isLeft = true;
	}
	if (this->mBoss3Data->Boss3->GetPosition().x >= 19509.3 + 80)
	{

		isLeft = false;
	}
	 count++;
	 if (isLeft==false) 
	 {
	 this->mBoss3Data->Boss3->SetVx(-350.0f);
	 if (count==50)
	 {
		 isDown =! isDown;
		
		 if (isDown)
			 this->mBoss3Data->Boss3->SetVy(-20.0f);
		 else  this->mBoss3Data->Boss3->SetVy(20.0f);
		 count = 0;
	 }
	
	 if (isDown) 
	 {
		
		 this->mBoss3Data->Boss3->AddVy(5.0f);
	 }
	 else {
		
		 this->mBoss3Data->Boss3->AddVy(-5.0f);
	 }
}
	 else {
		 this->mBoss3Data->Boss3->SetVx(350.0f);
		 if (count == 50)
		 {
			 isDown = !isDown;

			 if (isDown)
				 this->mBoss3Data->Boss3->SetVy(20.0f);
			 else  this->mBoss3Data->Boss3->SetVy(-20.0f);
			 count = 0;
		 }

		 if (isDown)
		 {

			 this->mBoss3Data->Boss3->AddVy(5.0f);
		 }
		 else {

			 this->mBoss3Data->Boss3->AddVy(-5.0f);
		 }
	 }
	 
	 count2++;
	 if(count2==400)
	 {
		 this->mBoss3Data->Boss3->SetState(new Boss3StandingState(this->mBoss3Data));
	 }
	 


}



Boss3State::StateName Boss3ZiczacBeeState::GetState()
{
	return Boss3State::ZiczacBee;
}

