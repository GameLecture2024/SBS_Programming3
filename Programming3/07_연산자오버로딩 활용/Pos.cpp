#include "Pos.h"

Pos::Pos() : Pos(0,0){}
Pos::Pos(int x, int y) : x(x), y(y){}
Pos::Pos(const Pos& other) : Pos(other.x,other.y){}
Pos::Pos(Pos&& rhs) noexcept = default;
Pos::~Pos() = default;

bool Pos::operator==(const Pos& other)
{
	return (x == other.x && y == other.y);
}

bool Pos::operator!=(const Pos& other)
{
	return !(*this == other);
}

Pos Pos::operator=(const Pos& other) 
{
	if (this == &other)
		return *this;

	x = other.x;
	y = other.y;
	return *this;
}

void Pos::Move(int x, int y)
{
	this->x += x;
	this->y += y;
}

void Pos::Teleport(Pos* other)
{
	x = other->x;
	y = other->y;
}

ostream& operator<<(ostream& os, const Pos& pos)
{
	os << "[x : " << pos.x << "," << "y: " << pos.y << " ]" << endl;
	return os;
}

istream& operator>>(istream& is, Pos& pos)
{
	//int x = 0, y = 0;
	// char*
	//is >> x;
	//is >> y;

	cout << "x의 값 :";
	is >> pos.x;
	cout << "y의 값 :";
	is >> pos.y;


	return is;
}
