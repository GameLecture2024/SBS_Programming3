#include "Base.h"

void Example()
{
	cout << "Example1 예제\n" << endl;
	Base base;
	base.display();
	Derived d;
	d.display();
	cout << endl;
}

// Base : Character   
// Derived : 전사, 마법사, 도적
void Example2()
{
	cout << "Example2 예제\n" << endl;
	Base* bptr = new Base;
	Derived* dptr = new Derived;
	Base* somePtr = new Derived;
	bptr->display();
	dptr->display();
	somePtr->display();
}

// 다형성 왜 쓰는가?
// interface 사용하는 것.
void Example4()
{
	cout << "Example4 예제\n" << endl;

	//Idisplayable* all_display[3];	    // 배열, vector
	Base* base_ptr = new Base;
	Base* d_ptr = new Derived;
	//Unit* unit_ptr = new Unit;

	base_ptr->display();
	d_ptr->display();
	//unit_ptr->display();
	
}
