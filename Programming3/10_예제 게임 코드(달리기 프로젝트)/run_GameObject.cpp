#include "run_GameObject.h"

run_GameObject::run_GameObject(int x, int y, string shape, int speed, int movetick)
	: x(x), y(y), shape(shape), speed(speed), movetick(movetick)
{}

run_GameObject::run_GameObject() : run_GameObject(80, 5, "This is example", 3)
{}

void run_GameObject::update()
{
	// 속도 변수(3).  속도를 체크하는 tick(0)    
	movetick++;
	if (speed <= movetick) // 내가 움직이고 싶은 속도에 도달했을 때
	{
		// 움직여라 코드. (다형성을 가지게 만들어라)
		move();

		movetick = 0;
	}

}

void run_GameObject::draw(ConsoleRenderer& console)
{
	console.Print(x, y, shape);
}

void run_GameObject::move()
{
	x--;
	if (x <= 0) { x = 80; }
}

jump_gameObject::jump_gameObject(int x, int y, string shape, int speed, int jumpPower, int movetick)
	: run_GameObject(x, y, shape, speed), jumpPower(jumpPower)
{	 
	jumpTime = 15;	  // 30장 -> 0.5초
	jumptick = 0;
	isGround = true;
}

jump_gameObject::jump_gameObject() : run_GameObject(), jumpPower(2)
{
	jumpTime = 15;
	jumptick = 0;
	isGround = true;
}

void jump_gameObject::move()
{
	jumptick++;
	if (jumpTime <= jumptick) // 내가 움직이고 싶은 속도에 도달했을 때
	{	
		if (isGround)
		{
			y -= jumpPower;
		}
		else
		{
			y += jumpPower;
		}
		isGround = !isGround;

		jumptick = 0;
	}

	run_GameObject::move();
}
