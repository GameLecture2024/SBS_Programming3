#include "Monster.h"

int Monster::GetStrength() const
{
	return _hp + _atk;
}

bool Monster::operator>(const Monster& other)
{
	return GetStrength() > other.GetStrength();
}

void Monster::Attack(BattleObject* other)
{
	cout << "플레이어에게 " << _atk << "만큼 데미지를 주었습니다!" << endl;

	other->Damage(_atk);
}
