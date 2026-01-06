#include "GameObject.h"

GameObject::GameObject(int id, RoomObjectType TYPE) : _id(id),r_TYPE(TYPE){}

BattleObject::BattleObject(int id, RoomObjectType TYPE, int hp, int atk) : GameObject(id,TYPE), _hp(hp), _atk(atk) {}

void BattleObject::Damage(int amount)
{
	_hp -= amount;
}

bool BattleObject::IsDeath()
{
	return _hp <= 0;
}


GameObject* BattleObject::GetObjectType()
{
	return this;   // 리턴 주소는 GameObject*이지만 실제 저장되어 있는 주소는 BattleObject
}


TreasureObject::TreasureObject(int id, RoomObjectType TYPE, int gold, string content)
	:GameObject(id, TYPE), _gold(gold), _content(content) {}

void TreasureObject::GetTreasure()
{
	cout << _content << "획득했습니다." << endl;
	cout << _gold << "을(를) 획득했습니다." << endl;
}

GameObject* TreasureObject::GetObjectType()
{
	return this;   // 리턴 주소는 GameObject*이지만 실제 저장되어 있는 주소는 TreasureObject
}