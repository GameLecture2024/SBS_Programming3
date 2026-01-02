#pragma once

#include "Monster.h"

class Player
{
private:
	int _hp;
	int _atk;
public:
	Player(int hp, int atk) : _hp(hp), _atk(atk) {}
	Player() : Player{ 1000, 100 } {}

	void Damage(int amount) { _hp -= amount; }
	bool IsDeath() { return _hp <= 0; }

	void Attack(Monster* mon)
	{
		mon->Damage(_atk);
	}
};

