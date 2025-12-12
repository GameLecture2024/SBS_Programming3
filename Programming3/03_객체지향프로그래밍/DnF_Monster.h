#pragma once
#include <iostream>
#include <string>

class DnF_Monster
{
	enum DungeonType{네임드, 보스, 주간};

private:
	std::string name;
	long long hp;
	int lineHp;

	void CalculateLineHP()
	{
		lineHp = hp / 25;
	}

public:
	// enum, 
	void SelectByDungeonType(DungeonType dType)
	{
		switch (dType)
		{
		case 네임드 : 
			break;
		case 보스 :
			break;
		case 주간:
			break;
		default:
			break;
		}
	}

	void ShowHpInfo()
	{
		// 실제 수치 + 줄 수
		// 실제 값을 25로 나눈 숫자를 줄로 표현하자.
		std::cout << hp << "/" << lineHp << std::endl;
	}
};

