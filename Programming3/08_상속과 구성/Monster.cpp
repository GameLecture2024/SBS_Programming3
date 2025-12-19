#include "Monster.h"

Monster::Monster()
{
	mov = new Moveable;
}

Monster::~Monster()
{
	delete mov;
}

void Monster::Move(int x, int y)
{
	mov->Move(x, y);
}

void Monster::Teleport(Pos* other)
{
	mov->Teleport(other);
}

void Monster::display_pos()
{
	cout << "몬스터의 좌표 : " << mov->get_pos();
}
