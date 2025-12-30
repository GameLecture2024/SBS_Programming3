// 
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "SmartPointer.h"
// STL : Standard Template Library 
// STL 사용이 능숙한 분 우대.

template<typename T>
class A
{
private:
	T value;
public:
	A(T a) : value(a) {}
	int operator+(const A&)
	{
		return 10;
	}
	T GetValue() { return value; }
};

class Item
{
private:
	std::string name;
public:
	Item(std::string n) : name(n) {}
	
	void display() const { std::cout << "아이템 이름: " << name << std::endl; }
};

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

/// ------------------------------
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}
//
//A Add(A a, A b)
//{
//	return a;
//}
// -------------------------------------------

enum class MoveType
{
	DASH = 0, JUMP = 1,
};

int main()
{

	std::unique_ptr<int> p1;
	std::vector<int> v1;
	static_cast<int>(0.25);

	// template 문법들을 사용하고 있었다.
	// 템플릿 무엇인가? 왜 쓰는가? 사용하는 법.
	// 기능을 비슷하게 가져온다. 데이터에 형태에 따라서 사용할 수도있고 못할 수 도 있다.
	double n1 = Add<int>(1.1, 3.1);
	std::cout << n1 << std::endl;

	A<int> a(1);       // A<int> 객체
	A<double> b(1.1);  // A<double> 객체
	A<int> c(2);
	std::cout << a + c << std::endl;
	std::cout << a.GetValue() << std::endl;
	std::cout << b.GetValue() << std::endl;
	std::cout << c.GetValue() << std::endl;

	std::cout << "\nTemplate 사용 예제" << std::endl;
	// int 배열
	std::vector<int> intArray = { 0,1,2,3,4,5 };
	for (auto& i : intArray)
	{
		i++;
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::vector<Item> inventory;
	Item i1("아이템1");
	Item i2("아이템1");
	inventory.push_back(i1);
	inventory.push_back(i2);
	for (const auto& i : inventory)
	{
		i.display();
	}

	int nn1 = static_cast<int>(MoveType::DASH);
	MoveType m_Type = static_cast<MoveType>(1);

	// 스마트 포인터 : delete 자동으로 해주는 객체다. (3종류 : unique, shared, weak)
	int* i_ptr1;
	
	{
		std::unique_ptr<int> my_unique_p1(new int);
		i_ptr1 = new int;
		*i_ptr1 = 10;
		*my_unique_p1 = 20;
		std::cout << "raw pointer value : " << *i_ptr1 << std::endl;
		std::cout << my_unique_p1.get();
		delete i_ptr1;
	}
	
	//std::cout << "smart pointer value : " << *my_unique_p1 << std::endl;

	Example1();
	Example2();
	Example3();
}