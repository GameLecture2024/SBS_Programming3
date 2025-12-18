#include "Player.h"

Player::Player()
{
	this->pos = new Pos;
}

Player::Player(Pos* pos)
{
	this->pos = new Pos;
	*(this->pos) = *pos;
}

Player::~Player()
{
	delete pos;
}

void Player::Move(int x, int y)
{
	pos->Move(x, y);
}

void Player::Teleport(Pos* other_pos)
{
	pos->Teleport(other_pos);
}

Pos& Player::get_pos() const
{
	return *pos;
}

void Player::display_pos() const
{
	cout << "플레이어의 좌표 : " << get_pos();
}
