#pragma once

#include <string>
#include "Player.h"

using namespace std;

class Monster
{
private:
	int _hp;
	int _atk;
	string _name;
public:
	int GetStrength() const { return _hp + _atk; }

	bool operator>(const Monster& other)  // 나의_hp (Monster)other._hp
	{
		return GetStrength() > other.GetStrength();
	}

	Monster(int hp, int atk, string name) : _hp(hp), _atk(atk), _name(name) {}
	Monster() : Monster{ 100, 10, "이름없음" } {}

	void Damage(int amount) { _hp -= amount; }
	bool IsDeath() { return _hp <= 0; }

	void Attack(Player& player)
	{
		player.Damage(_atk);
	}
};

