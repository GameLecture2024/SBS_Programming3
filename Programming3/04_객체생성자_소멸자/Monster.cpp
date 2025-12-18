#include "Monster.h"
#include "Monster.h"

// delegate 위임 생성자
// 매개변수 몇개든 간에 모든 생성자는 하나의 생성자 코드로만 구현할 수 있다.

Monster::Monster() : Monster{"이름없음",0,0,"미정의",battleType::UnDefined, 0}
{
}

Monster::Monster(string name, int HP, double evade, string type, battleType enumType, int speed) 
	: name(name), HP(HP), evade(evade), type(type), enumType(enumType), speed(speed)
{
	// 포인터 동적할당
	iptr = new int;
}

Monster::~Monster()
{
	delete iptr;
}

void Monster::SetPtrValue(int value)
{
	*iptr = value;
}

Monster::Monster(const Monster& other) : Monster{ other.name,other.HP,other.evade,other.type,other.enumType,other.speed }   // 
{
	cout << "복제 생성자" << endl;

	*iptr = *other.iptr;
}

Monster::Monster(Monster&& rhs)
{
	cout << "이동 생성자" << endl;

	*iptr = *rhs.iptr;
}
