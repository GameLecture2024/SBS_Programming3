#pragma once

#include "GameObject.h"
#include <iostream>

using namespace std;

class Player : public BattleObject
{
public:
	Player(int id, int hp, int atk); 
	Player(); 

	void Attack(BattleObject* mon) override;

};

