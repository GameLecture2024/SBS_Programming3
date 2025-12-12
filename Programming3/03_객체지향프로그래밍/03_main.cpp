#define _CRT_SECURE_NO_WARNINGS
#include <cstring>	 // strcpy
#include <iostream>
#include "Person.h"

using namespace std;

// c vs cpp 차이점
// c언어 - 절차 지향 언어 - 함수들로 구성된 프로그램
// cpp  - 객체 지향 언어  - 객체들로 구성된 프로그램

// c언어 프로그래밍을 하면서 겪었던 문제점
// 구조체 안의 데이터를 추가해서 사용을 해야한다.

// 프로그래밍의 확장이 어려워진다.
// 모든 객체의 정보를 알고 있어야 함수를 다룰 수 있다.
// 프로그램이 커지면 커질수록 다루기가 어려워 진다.

// 대입 연산자로 데이터를 초기화를 하고 있다.
// 참조 타입, 주소를 사용하는 데이터를 대입하면 어떤 일이 일어날까요?
// 주소 데이터를 대입한 후에 하나의 객체를 지워보세요.
// 이것을 해결하기 위한 방법?


struct Monster
{
	int id;
	int hp;
	char* name;    // 주소 에러. 초기화
};

int main()
{
	Monster mon;
	mon.name = new char[100];
	mon.id = 1;
	mon.hp = 10;
	strcpy(mon.name,"오크");
	cout << mon.name << endl;
	
	Monster mon2;
	mon2 = mon;	   // mon2
	delete[] mon.name;
	cout << "3강" << endl;

	// 얕은 복사(shallow copy) 깊은 복사(deep copy)

	Person p1{};
	Person p2(20, "홍길동", "부산");
	p1.ToString();
	p2.ToString();

	Person p3(1000, 20, "김김김", "서울");
	p3.ToString();

	Person p4(500, 30, "춘향이", "조선", "미인");

	// 직접 클래스를 동적할당 해보자.
	Person* p_ptr = new Person(700, 42, "몽룡이", "조선", "양반");
	delete p_ptr;

}