#include <iostream> // cout, cin
#include <cstdio>   // cpp 방식 호출   c언어에서 사용했던 라이브러리 사용하고 싶을 때는
// #include <stdio.h>	// c언어 방식 호출
#include <strstream>

using namespace std;

// 주소를 저장하는 변수
// (1) cpp 방식의 변수 선언.
// (2) 포인터의 동적 할당 변경 사항
// (3) 참조자

// int& a = b1; int& b = b2;
void MySwap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

void MySwap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

int& RefExample(int& mainRef)
{
	int temp = ++mainRef;
	return temp;
}

struct Pos
{
	int x;
	int y;
};

void ChangePos(Pos& pos, int addXValue, int addYValue) // 임시로 가져올 값 - 그냥 임시 변수
{
	pos.x += addXValue;
	pos.y += addYValue;
}

// 포인터를 대체 할 수 있는가? 
// 참조자로는 표현할 수 있는 내용이 잇다. - 참조자가 null이 될 수 없다.

// fp* 폴더의 파일 이름이 없으면 실행하지마라.

// 함수 안에서 값을 변경하는 코드는 참조자를 쓰겠다. 코딩 스타일

// 포인터를 사용하는 이유? 
// 함수 안에서 데이터를 변경할 수 있게 한다.
// 효율적으로 데이터를 전달하고 사용할 수 잇다.

void SomePos(const Pos& pos)
{
	pos.x;
}

/*
*   아래 내용을 정리해보세요
*   (1) 포인터를 사용하는 이유.
* 
*   (2) 참조자를 사용할 때의 주의 사항.
* 
*   (3) 포인터와 참조자를 같이 사용해야 하는 이유.
*/

// 참조자를 이용해서 값을 변경하는 예제를 구현해보세요

// 참조자를 이용해서 값을 변경하지 않는 예제를 구현해보세요.


int main()
{
	cout << "2강 포인터와 참조자" << endl;

	// 보충 설명  :: ends << 뭔가요
	std::ostrstream oss;
	oss << "샘플 텍스트: " << 42 << std::ends;  // flush
	cout << "!!" << oss.str() << "!!" << endl;
	std::printf("!! %s !!\n ", oss.str());// 문자열은 끝이 널문자여야 한다.
	//
	
	cout << "\n2-1 cpp 방식의 변수 선언." << endl;

	int a = 10.5; // c언어 방식의 변수 초기화
	int a2(20.5); // cpp언어에서의 변수 초기화 방식.
	int a3{ 30 }; // cpp언어에서의 변수 초기화 방식2.

	cout << a << endl;
	cout << a2 << endl;
	cout << a3 << endl;

	int* a_ptr = &a;
	int* a2_ptr{ nullptr };
	int* a3_ptr{};
	cout << a_ptr << endl;
	cout << a2_ptr << endl;
	cout << a3_ptr << endl;

	cout << "\n2-2 nullptr 주소에 주소 생성하기 런타임 시점에." << endl;

	a2_ptr = new int;
	cout << a2_ptr << endl;
	*a2_ptr = 10;
	cout << *a2_ptr << endl;

	delete a2_ptr;

	// 스마트 포인터 -> 포인터 할당 후 메모리 누수가 문제가 된다(프로그래머의 실력에 따라서)

	cout << "\n2-3 swap함수 예제 " << endl;

	int b1{};
	int b2{};
	cin >> b1;
	cin >> b2;
	cout << "b1의 값 : " << b1 << endl;
	cout << "b2의 값 : " << b2 << endl;
	MySwap(b1, b2);
	cout << "b1의 값 : " << b1 << endl;
	cout << "b2의 값 : " << b2 << endl;

	// 참조자가 어떤 원리인가? 이러한 기능이 가능해지는가?

	cout << "\n2-4 참조자 " << endl;

	// 선언 방법
	int& aRef = a; // aRef별명 a이름의 변수에   홍길동 alias

	int* c_ptr{}; // new 키워드를 사용해서 주소를 할당.
	// new
	c_ptr = new int;

	cout << c_ptr << endl;
	int*& c_ptrRef = c_ptr;
	delete c_ptr;
	cout << c_ptrRef << endl;    
	// 둘의 주소를 출력해보세요 

	int* c2_ptr{};
	c2_ptr = new int;
	int* c2_ptr2 = c2_ptr;  // 복제  -> 깊게 이해
	cout << c2_ptr << endl;
	delete c2_ptr;
	cout << c2_ptr2 << endl;

	// 주소를 생성할 때 복제를 할 수 있고, 참조를 할 수 있다. 
	// cpp 매우 빠른 코드.

	// 참조자 사용 시 주의사항
	// 1. 참조자는 선언과 동시에 초기화를 해줘야 한다.

	// int& myRef;  
	//const int& myRef = 10;
	
	// 2. 함수에서 반환하는 값이 소멸되지 않도록 해야한다. 

	int mainNum = 10;
	int& refValue = RefExample(mainNum); // refValue RefExample함수안에 있는 temp의 별명
	
	cout << refValue << endl; // 컴파일러 Undefined 정의되지 않은 코드는 알아서 수정하도록.
	                          // dangling 임시 객체


	Pos myPos{};
	ChangePos(myPos,2,5);

	cout << "X : " << myPos.x << "Y : " << myPos.y << endl;
}