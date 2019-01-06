#include "BeeState.h"
#include "BeeFlyingState.h"

//#include "PlayerFallingState.h"



BeeFlyingState::BeeFlyingState(BeeData *BeeData)
{
	this->mBeeData = BeeData;

	count = 0;
	time = 200;
}


BeeFlyingState::~BeeFlyingState()
{

}

void BeeFlyingState::Update(float dt)
{

	
	/*this->mBeeData->Bee->SetVx(-100);
	if (this->mBeeData->Bee->GetPosition().x<= (19509.3 - 500))
		this->mBeeData->Bee->SetVx(0);*/

}



BeeState::StateName BeeFlyingState::GetState()
{
	return BeeState::Flying;
}

