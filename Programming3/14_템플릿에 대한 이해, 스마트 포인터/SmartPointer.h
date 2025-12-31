#pragma once

#include <iostream>
#include <memory>

using namespace std;

// Heap 영역을 가리키고 있는 참조하고 있는 수가 0이면 Heap을 자동으로 소멸시켜라. - 스마트 포인터.

// unique_ptr :	힙을 가리키는 포인터가 유일하다. std::move()
// shared_ptr :
// weak_ptr	  :

class SmartPointer
{
	unique_ptr<int> uptr;
	shared_ptr<int> sptr;
	weak_ptr<int> wptr;
};

class Sharedptr
{
public:
	shared_ptr<int> sptr;
	void setPointer(shared_ptr<int> other)
	{
		sptr = other;
	}

	void setPointer(int value)
	{
		sptr = make_shared<int>(value);		             // new 키워드 없이 동적할당 해주는 함수.
	}

	void getValue()
	{
		std::cout << *sptr << std::endl;
	}
};

class Police;
class Gun;

class Police {
public:
	shared_ptr<Gun> myGun;

	~Police() { cout << "경찰이 소멸되었습니다." << endl; }
};

class Gun
{
public:
	weak_ptr<Police> owner;

	~Gun() { cout << "총이 소멸되었습니다." << endl; }
};


class UEx
{

public:
	unique_ptr<int> uptr;
	void setPointer(unique_ptr<int> other)	// 유일 포인터는 자기 자신만 힙을 가리켜야 한다.
	{
		uptr = std::move(other);		    // move함수를 사용해서 임시 객체로 만들어야 한다.
	}

	void setPointer(int value)
	{		
		uptr = std::make_unique<int>(value);	 // unique_ptr<int> uptr(new int{value});
	}

	void getValue()
	{
		std::cout << *uptr << endl;
	}
};

void Example1();
void Example2();
void Example3();

