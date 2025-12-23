#pragma once

#include <string>
#include "ConsoleRenderer.h"
using namespace std;
class run_GameObject
{
private:
	int x;	
	string shape;
	int speed;
	int movetick;
protected:
	int y;
public:
	run_GameObject(int x, int y, string shape, int speed, int movetick = 0);
	run_GameObject();

	void update();
	void draw(ConsoleRenderer& console);
	virtual void move();
};

class jump_gameObject : public run_GameObject
{
private:
	int jumpPower;
	bool isGround;	
	int jumpTime;  
	int jumptick;
public:
	jump_gameObject(int x, int y, string shape, int speed,int jumpPower, int movetick = 0);
	jump_gameObject();
	virtual void move() override;
};


