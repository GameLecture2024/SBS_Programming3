// 접근 지정자.
// 생성 - 소멸자
// 상속 - 구성
// 스마트 포인터

// STL c++ 개발자(게임) - STL 잘아시나요?
// Standard Template Library (신뢰할 수 있는 라이브러리) 
// 자료구조 - 알고리즘

// 컨테이너 알고리즘(Algorithm) 반복자(iterator)

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#include "Player.h"



// Room 게임 등장하는 게임 요소를 인카운트 시키는 객체이다.
// iterator<Room> iterator++

struct CompareStrength
{
	bool operator()(const Monster* a, const Monster* b)
	{
		return a->GetStrength() < b->GetStrength();
	}
};

class Room
{
	// Monster* unique_ptr<Monster>
private:
	vector<Monster*> AvailableMonsters; // 랜덤한 몬스터들이 배정되어 있다.
	vector<Monster*> settingsMonster;   // 약한 몬스터가 0번 배열에 저장이 되어 있다.
public:
	void Initialize(const vector<Monster*>& copyMonsters)
	{
		AvailableMonsters = copyMonsters;
	}


	// 몬스터 들의 강함 순위를 정해서 약한 몬스터가 앞에서 등장하게 구현하고 싶다.  (순서를 재정렬하고 싶다.)

	void SetOrder()   // 알고리즘 라이브러리를 가져와서 코드를 실행하겠다.
	{
		settingsMonster = AvailableMonsters;
		std::sort(settingsMonster.begin(), settingsMonster.end(), CompareStrength());
	}

	int RoomCount() { return settingsMonster.size();}

	Monster* Encount(int roomIndex) { return settingsMonster[roomIndex]; }

	// 0   ~   10     [5    end]
	// 정렬을 해주지 않았다.
	// 어떤 내용을 기준으로 정렬할 것인가?
	//  
	// int arr[5];   arr(주소) + i0] [i1] [i2] [3] [4] ....
};



class BattleManager
{
private:
	void Battle(Player& player, Monster* mon)
	{
		// 턴
		while (true)
		{
			int playerIndex = 0;
			cout << "플레이어의 턴!" << endl;

			// 내가 먼저 공격
			cin >> playerIndex;  // 대기 하라.
			player.Attack(mon);

			// 니가 공격
			mon->Attack(player);

			if(player.IsDeath() || mon->IsDeath())
			{
				break;
			}

		}
	}

public:	
	void PlayRoom(Player& player, Room room)
	{
		 int battleCount = room.RoomCount();

		 for (int i = 0; i < battleCount; i++)
		 {
			 // 전투

			 // 첫번째 방에 있는 오브젝트[몬스터]와 조우했다.
			 Monster* mon = room.Encount(i);

			 Battle(player, mon);

			 // 플레이어가 사망했으면?
			 if (player.IsDeath()) 
			 {
				 return;
			 }
		 }		 
	}
};

// player.   battleManager

int main()
{
	cout << "16강 STL 예제 " << endl;

	Room room;
	vector<Monster*> copyMonsters;
	copyMonsters.push_back(new Monster(60, 6, "B"));   // 66
	copyMonsters.push_back(new Monster(50, 5, "A"));   // 55
	copyMonsters.push_back(new Monster(80, 8, "D"));   // 88
	copyMonsters.push_back(new Monster(70, 7, "C"));   // 77

	room.Initialize(copyMonsters);
	room.SetOrder();

	Player player;
	// room에 있는 몬스터와 만났다.
	BattleManager _bm;
	_bm.PlayRoom(player, room);
}