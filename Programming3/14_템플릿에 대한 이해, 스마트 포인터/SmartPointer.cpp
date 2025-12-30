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

	Police p1;
	Gun gun;
	p1.myGun = make_shared<Gun>(gun);
	gun.owner = make_shared<Police>(p1);

	gun.owner.reset(); // 경찰이 총을 집어들어서 생성되어 있던 gun 정보를 없앴다.
	p1.myGun.reset();  // 내가 가지고 있는 총의 포인터를 지우겠다.
	std::cout << p1.myGun.use_count() << std::endl;
	std::cout << gun.owner.use_count() << std::endl;
}