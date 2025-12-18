#pragma once

#include "Moveable.h"

class Monster
{
private:
	Moveable* mov;
public:
	Monster();
	Monster(const Monster& other);
	Monster(Monster&& rhs);
	~Monster();
	
	void Move(int x, int y);
	void Teleport(Pos* other);
	void display_pos();
};

