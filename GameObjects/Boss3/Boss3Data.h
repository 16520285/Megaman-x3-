
#pragma once
//pre define

class Boss3;
class Boss3State;
class Player;

class Boss3Data

{
public:
	Boss3Data() {};
	~Boss3Data() {};
	Player *Player;
	Boss3 *Boss3;
	Boss3State *Boss3State;
	float PlayerX,PlayerY;
	bool mCurrentReverse;
	int attackTime=0;
	int attackTime2 = 4;
	int generateBee = 0;
	bool isAttack=false;
	bool BeeRight=false;
protected:

};