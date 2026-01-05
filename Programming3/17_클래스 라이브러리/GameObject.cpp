#include "GameObject.h"

GameObject::GameObject(int id) : _id(id){}

BattleObject::BattleObject(int id, int hp, int atk) : GameObject(id), _hp(hp), _atk(atk) {}

void BattleObject::Damage(int amount)
{
	_hp -= amount;
}

bool BattleObject::IsDeath()
{
	return _hp <= 0;
}

