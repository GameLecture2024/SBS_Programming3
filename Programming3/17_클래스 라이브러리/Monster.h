#pragma once

#include "GameObject.h"
#include <string>
#include <iostream>

using namespace std;

class Monster : public BattleObject
{
private:
	string _name;
public:
	int GetStrength() const;

	bool operator>(const Monster& other);  // ³ªÀÇ_hp (Monster)other._hp


	Monster(int id, RoomObjectType TYPE, int hp, int atk, string name);

	void Attack(BattleObject* mon) override;

};

