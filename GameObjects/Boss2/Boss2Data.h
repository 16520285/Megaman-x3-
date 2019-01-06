
#pragma once
//pre define

class Boss2;
class Boss2State;


class Boss2Data

{
public:
	Boss2Data() {};
	~Boss2Data() {};
	
	Boss2 *Boss2;
	Boss2State *Boss2State;
	bool isAttack=true;
	bool faceRight = true;
	int standingTime = 0;
	int standingTime2 = 3;
	int standingTime3 = 5;
protected:

};