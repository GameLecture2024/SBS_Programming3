#include "Player.h"
#include "Monster.h"
#include "Moveable.h"

// 중복되는 것들은 하나로 표현하자.
// 정적 라이브러리 .lib

// 데이터 구조를 확장하기 위해서 클래스안에 클래스 넣으면 되구나.

// 상속(Inheritance) : 내가 가진 모든 것을 자식에게 물려주겠다.
// 내가 가진 모든 것이 공통으로 반복된다면 이것을 어떻게 한번만 처리할 수 있을까?

// 구성(Composition) : 상속이 아닌 경우에 객체를 추가할 때 사용한다.

int main()
{
	Monster m1;
	m1.display_pos();
	Player p1;
	p1.display_pos();

	Moveable mov;
	Flyable fly(3);
	fly.Fly(3,5);
	fly.display_pos();

	//mov.Move(1,1);
	//fly.Move(1,1);
	//fly 자식 클래스는 Move() 함수를 소유하고 있다. 부모 클래스의 Move(int x, int y)

	cout << "상속된 클래스 맴버 함수 재사용하기" << endl;  // 부모클래스::함수이름();
	Moveable* movptr = new Moveable;
	Flyable* flyptr = new Flyable(3);

	movptr->Move(1, 1);
	movptr->display_pos();
	flyptr->Move(3,3);
	flyptr->display_pos();

	cout << "클래스의 다형성 " << endl;

	Moveable* ffptr = new Flyable(3);
	Moveable* mmptr = new Moveable;
	ffptr->Move(1, 1);
	mmptr->Move(1, 1);
	
	// 다형성 코드를 사용할 때의 주의사항.

	// LightingMovalbe  

	// Moveable 객체. Fly, Roll, Crawl
	// if(Moveable) Move();
}