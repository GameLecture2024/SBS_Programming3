#pragma once

#include <string>
#include <iostream>

using namespace std;

enum class battleType {
	불경, 인간 , UnDefined
};

// class, struct
// 함수가 존재하면 class로 선언하라.
// 함수가 필요없으면 struct로 선언하라.

class Monster
{
private:
	string name;          // 몬스터의 이름
	int HP;               // 체력
	double evade;         // 회피
	string type;          // 추가 데미지를 적용할 수 있는 타입인가? 주소안에 있는 값이 모두 같은가?
	battleType enumType;  // enum 0 : 불경
	int speed;			  // 생성자를 추가하여 구현해보세요

	int* iptr; // 예제. deep copy를 위한

public:
	// 생성자
	Monster();    // no args 생성자. 기본값으로 전부다 설정해줘.
	Monster(string name, int HP, double evade, string type, battleType enumType, int speed); // overloading 생성자

	Monster(const Monster& other);  // copy 생성자    shallow copy, deep copy -> new키워드로 메모리 생성 후 값 복사.
	Monster(Monster&& rhs);		   // move 생성자	. B(new 생성 -> 삭제) Temp <- b;

	~Monster(); // 소멸자

	// 멤버 함수

	void SetPtrValue(int value);
};


