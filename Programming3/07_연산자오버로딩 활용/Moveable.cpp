#include "Moveable.h"

Moveable::Moveable()
{
	this->pos = new Pos;
}

Moveable::Moveable(Pos* pos)
{
	this->pos = new Pos;
	*(this->pos) = *pos;
}

Moveable::~Moveable()
{
	delete pos;
}

void Moveable::Move(int x, int y)
{
	pos->Move(x, y);
}

void Moveable::Teleport(Pos* other_pos)
{
	pos->Teleport(other_pos);
}

Pos& Moveable::get_pos() const
{
	return *pos;
}

void Moveable::display_pos() const
{
	cout << "플레이어의 좌표 : " << get_pos();
}