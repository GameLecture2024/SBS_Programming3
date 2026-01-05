#include "Player.h"

Player::Player(int id, int hp, int atk)
	: BattleObject(id, hp, atk) {}

Player::Player() 
	: Player{ 1001, 1000, 100 } {}

void Player::Attack(BattleObject* other)
{
	cout << "몬스터에게 " << _atk << "만큼 데미지를 주었습니다!" << endl;

	other->Damage(_atk);
}
