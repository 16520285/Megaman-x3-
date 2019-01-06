
#pragma once
//pre define

class Boss1;
class Boss1State;

class Boss1Data

{
public:
	Boss1Data() {};
	~Boss1Data() {};

	Boss1 *Boss1;
	Boss1State *Boss1State;
	int horizontalTime = 0;
	int movingTime = 0;
	int movingZiczacTime = 0;
	int bornTime = 0;
protected:

};