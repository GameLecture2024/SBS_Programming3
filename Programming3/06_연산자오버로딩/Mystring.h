#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // strcpy, strcom, strlen
using namespace std;

// 포인터가 있으면 -> 복사,이동 연산자 직접 구현

class Mystring
{
	friend ostream& operator<<(ostream& os, const Mystring& obj);
	friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);
private:
	char* str;
public:
	Mystring(); // 기본 생성자
	Mystring(const char* source);  // 중첩 정의 생성자 overload constructor
	Mystring(const Mystring& other); // 복사 생성자
	Mystring(Mystring&& rhs) noexcept; // 이동 생성자
	~Mystring(); // 소멸자

	// 연산자 오버로딩
	Mystring operator=(const Mystring& other);
	Mystring operator=(Mystring&& rhs) noexcept;

	//Mystring operator+(const Mystring& other);    // +연산자를 재정의.  a = a1 + " ";
                                                  // 왼쪽(rvalue) + 객체 => 실행을 못한다.
	// 멤버 함수로 구현
	Mystring CopyAssignment(const Mystring& other);
};

