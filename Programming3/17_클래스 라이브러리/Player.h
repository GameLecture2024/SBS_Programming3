#pragma once

#include "GameObject.h"
#include <iostream>

using namespace std;

class Player : public BattleObject
{
public:
	Player(int id, RoomObjectType TYPE, int hp, int atk);
	Player(); 

	void Attack(BattleObject* mon) override;

};

