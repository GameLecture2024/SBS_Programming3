#pragma once

// 순수 가상 함수 :
// 문법 : virtual 키워드를 붙인 함수 뒤에 = 0;
// 개념 : 구현을 자식에게 위임하는 문법

// 인터페이스 : (공격클래스)-> 인터페이스 <- (유닛)
// 유닛 - 추상적인 개념	 has (공격한다 기능)
// 저글링, 오버로드, 드론
// I를 붙여서 인터페이스 임을 알리자.

// 함수 이름 없이 표현하는 문법 람다식.
// 배열 << 자료구조, 알고리즘

#include <iostream>
using namespace std;

class Idisplayable
{
public:
	virtual void display() const = 0;
};

// 3. (테란, 저그, 프로테스) => 어떻게 표현할 것인가?

// 종족 개념 : 

class Race
{
	// 종족 마다 다른 특징을 공통으로 표현하게 구성.
public:
	// 종족 특징
};

class Unit : public Idisplayable
{
	// Idisplayable을(를) 통해 상속됨
public:
	void display() const override;
};

class ZergUnit : public Unit
{
public:
	ZergUnit() = default;
};

// ZergUnit

// 건물은 생산을 해야 한다.  
// 
class IMakeable 
{
public:
	virtual void make_unit() = 0;
};

class Building : public IMakeable
{
public:
	virtual void make_unit() override;
};

class Zerg_Building : public Building
{
	// 초당 체력을 회복한다.
};

class Terran_Building : public Building
{
	// 수리가 가능하다
};

class Protoss_Building : public Building
{
	// 쉴드를 가진다.
};


void Example3(); // pure virtual function

