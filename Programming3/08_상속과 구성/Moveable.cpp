#include "Moveable.h"

Moveable::Moveable()
{
	cout << "Moveable 객체 생성" << endl;
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
	cout << "Moveable 소멸자 호출" << endl;
}

void Moveable::Move(int x, int y)
{
	cout << "Moveable의 이동이다." << endl;
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

Flyable::Flyable(int _flyWeight) : Moveable(), flyWeight(_flyWeight)
{
	cout << "Flyable 객체 생성" << endl;
}

Flyable::~Flyable()
{
	cout << "Flyable 소멸자 호출" << endl;
}

void Flyable::Move(int x, int y) 
{
	cout << "Flyable의 이동이다" << endl;
	Fly(x, y);
}

void Flyable::Fly(int x, int y) 
{
	// 몬스터의 y.pos 표현값을 - 3 ~ 6

	Moveable::Move(x * flyWeight, y * flyWeight);//   y의 높이가  
}
