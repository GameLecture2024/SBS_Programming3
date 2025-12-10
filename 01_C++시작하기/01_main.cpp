// c언어 학습 한 상태.  
// c++ 시작하기(배우기)
// c -> c++ 이름이 변경되면서(새언어) 어떤 기능이 다를까?
// 새로운 언어를 사용하게 될 가능성.
// c언어 기능(메인) -> 다른 언어에서는 어떻게 표현하고 있을까
// Hello World 출력해봐라

#include <stdio.h>
#include "01_이름공간.h"
#include "Monster.h"
//using namespace A;
using A::ShowPlayer;
using namespace std;

int main()
{
	printf("C Style \n");
	printf("Hello World!\n");

	cout << "Cpp Style" << " append" << endl;
	cout << "Hello World!" << endl;

	A::ShowPlayer();

	cout << "사용자 정의 자료형을 사용하기 : Struct" << endl;

	// char name[100]; name = "슬라임"; //  주소 <- 주소
	//strcpy(monclass.name, "슬라임);   이름을 오른쪽 이름을 왼쪽에 옮기고 싶은데.. 특별한 함수로 써야한다
	Monster monclass;
	monclass.name = "슬라임"; //  string 문자열을 표현하는 객체.. 주소로 이루어 져있겠지?
                             // c언어 사용하는 문법이 전혀 다르다. 암기로 시작하면 머리가 아파집니다.
	monclass.HP = 100;
	monclass.UID = 1;

	cout << "몬스터의 이름 :" << monclass.name << endl;
	cout << "몬스터의 체력 :" << monclass.HP << endl;
	cout << "몬스터의 UID :" << monclass.UID << endl;

}

// (1) (이름) :: (이름) 이게 무슨 문법이지?	 - 이름 공간(namespace)
// 스코프(범위) 연산자 :: ,, { } 영역을 표현한다.
// - namespace 키워드를 선언.
// - namespace 사용한다. using 키워드 함께						   
// 
//  ends vs endl 차이점
// 
// 
// (2) << 어떻게 사용되고 있는 것인가? 
// (3) std::endl;

// C언어와 Cpp언어 변경 사항이 무엇이 있었을까?
// 1. 함수 오버로딩(overloading)   
// - C언어 : 반환값  이름(... )
// - cpp  : 이름 같더라도 인자가 다르면 다른 함수로 인식하자.

// 게임을 만들기 위해서.
// 컴퓨터에게 명령에서 실행하게 만든다.
// 게임안에 있는 데이터를 만들고 싶은거죠.
// 배운 내용을 데이터로 표현하려고 연습.

// struct(구조체) - class(클래스,객체) 하는 역할을 같습니다.
// 의미적으로는 다르다.

// 포인터, 참조자
// - 사용자를 위한 문법
// cpp 만들어진 코드가 쓰고 싶다 vs 설계 해보고 싶다.
// C언어 프로젝트에서 사용한 게임 데이터를 범용으로 사용할 수 있게 변경하기.