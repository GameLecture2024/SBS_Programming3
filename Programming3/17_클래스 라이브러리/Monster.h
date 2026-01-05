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


	Monster(int id, int hp, int atk, string name) : BattleObject(id, hp, atk), _name(name) {}

	void Attack(BattleObject* mon) override;

};

