
// 플레이어 player
// 스킬	   skill

#include "Skill.h"
#include "Windows.h"



int main()
{
	// 데이터를 표현한다. 데이터를 포인터로 관리한다. 스마트 포인터로 표현.
	unique_ptr<Skill> garenPassive = make_unique<Garen_Passive>();
	unique_ptr<Skill> garenQ = make_unique<Garen_Q>();
	unique_ptr<Skill> garenW = make_unique<Garen_Q>();
	unique_ptr<Skill> garenE = make_unique<Garen_Q>();		   // ("Q스킬 정보")
	unique_ptr<Skill> garenR = make_unique<Garen_Q>();

	// 데이터를 사용하는 객체가 필요하다.

	Player Garen;
	
	Garen.setSkill(make_unique<Garen_Passive>());
	Garen.setSkill(make_unique<Garen_Q>());
	Garen.setSkill(make_unique<Garen_Q>()); // W
	Garen.setSkill(make_unique<Garen_Q>());	// E
	Garen.setSkill(make_unique<Garen_Q>());	// R

	//Garen.useSkill(1); // cin >> "Q" Q가 발동.


	//Skill* garenPassive = new Garen_Passive();
	//Skill* garenQ = new Garen_Q();

	

	while (true)
	{
		// 플레이어의 입력

		Garen.update(); // 입력

		Sleep(17);    
	}

}