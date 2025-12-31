#include "SmartPointer.h"

// 몬스터.
// 클래스(drop, stat...)

void Example1()
{
	std::cout << std::endl;
	std::cout << "Smart Point : Unique Example" << std::endl;
	UEx unique;
	unique.setPointer(std::make_unique<int>(20));
	unique.getValue();
	unique.setPointer(10);
	unique.getValue();
}

void Example2()
{
	std::cout << std::endl;
	std::cout << "Smart Point : Shared Example" << std::endl;
	Sharedptr shared;
	Sharedptr shared2;

	shared.setPointer(10);
	shared2.setPointer(shared.sptr);
	shared.getValue();
	shared2.getValue();           

	std::cout << "공유 포인터가 가리키고 있는 수 : " << shared.sptr.use_count() << std::endl;		// 2
	shared.sptr.reset();
	std::cout << "공유 포인터가 가리키고 있는 수 : " << shared.sptr.use_count() << std::endl;	    // 0
	std::cout << "공유 포인터가 가리키고 있는 수 : " << shared2.sptr.use_count() << std::endl;
}

void Example3()
{
	std::cout << std::endl;
	std::cout << "Smart Point : Weak Example" << std::endl;

	shared_ptr<Police> p1 = make_shared<Police>();	// new Police() 대신 사용한다;
	shared_ptr<Gun> gun = make_shared<Gun>();
	p1->myGun = gun; // 경찰이 소유한 총이 Gun을 가리킨다.
	gun->owner = p1; // 총의 소유자는 p1이다.

	std::cout << p1->myGun.use_count() << std::endl;
	std::cout << gun->owner.use_count() << std::endl;
}