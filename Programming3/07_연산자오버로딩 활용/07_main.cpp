#include <iostream>
#include "Pos.h"
#include "Player.h"
#include "Monster.h"
using namespace std;

int main()
{
	// 위치 표현
	// 2D(x,y) 
	// 3D(x,y,z)
	{
		Pos p1;
		Pos p2(3, 5);
		Pos p3(p2);
		Pos p4(std::move(p3));

		if (p1 == p4) // 둘의 좌표가 같습니까?
		{
			cout << "p2와 p3의 좌표가 같습니다." << endl;
		}
		else {
			cout << "p2와 p3의 좌표가 다릅니다." << endl;
		}

		if (p1 != p2)
		{
			cout << "다릅니다" << endl;
		}

		//cin >> p1;
		//cout << "p1의 데이터 \n" << p1;
		//cin >> p2;
		//cout << "p2의 데이터 \n" << p2;
	}
	Pos startPlayerPos(5, 5);
	Pos* dungeonPosPtr = new Pos(100,100);
	Player p1(&startPlayerPos);

	p1.Move(1, 1);
	p1.display_pos();
	p1.Teleport(dungeonPosPtr);
	p1.display_pos();
	delete dungeonPosPtr;

	Monster m1;
	m1.Move(3, 5);
	m1.display_pos();
}