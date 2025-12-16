#pragma once

#include <iostream>

using namespace std;

// 어떤 데이터를 저장해야 하는가? 멤버 변수

// 어떤 기능을 처리하는가? withdraw(인출) deposit(저축)
		
// 클래스랑 함께 사용하면 좋은 키워드

// Getter Setter 함수 표현
// 기본으로 주는 금액을 1000 -> 10000
class Account
{
private:
	static constexpr int default_currnecy = 10000;
	int currency;
	int* iptr;
public:	
	Account();	           // 기본 생성자  default
	Account(int money);    // 중첩 정의 생성자 overload constructor
	Account(const Account& other); // 복사 생성자 copy constructor
	Account(Account&& other) noexcept;      // 이동 생성자 move
	~Account();

	// Getter Setter 함수를 만드세요
	int get_currency() const
	{
		return currency; 
	}  // 함수를  const화 시키는 키워드
	void set_currency(int money)  
	{
		currency = money; 
		if (currency < 0) { currency = 0; }
	}

	// (기능) 맴버 함수, 메소드(method)
	int withDraw(int amount);
	void deposit(int amount);

	// 연산자 오버로딩
};







