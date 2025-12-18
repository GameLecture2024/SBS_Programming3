#pragma once

#include <iostream>
// struct, class : 함수를 선언하려면 클래스로 구현하세요.
using namespace std;
class Pos
{
	friend ostream& operator<<(ostream& os, const Pos& pos);
	friend istream& operator>>(istream& is, Pos& pos);
private:
	int x;
	int y;
public:
	Pos();
	Pos(int x, int y);
	Pos(const Pos& other);
	Pos(Pos&& rhs) noexcept;
	~Pos();

	// 연산자 오버로딩
	bool operator==(const Pos& other);
	bool operator!=(const Pos& other);

	Pos operator=(const Pos& other); // 복사 할당 copy assignment

	void Move(int x, int y);
	void Teleport(Pos* other);
};

