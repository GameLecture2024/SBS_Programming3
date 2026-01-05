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
#include "Monster.h"
#include "Windows.h" // Sleep();

// Room 게임 등장하는 게임 요소를 인카운트 시키는 객체이다.
// iterator<Room> iterator++

struct CompareStrength
{
	bool operator()(const Monster* a, const Monster* b)
	{
		return a->GetStrength() < b->GetStrength();
	}
};

// 반복이 계속되는 것을 피하고 싶다..
// 조금더 최적화된 코드를 작성하고 싶다. 
// 어떤 기준으로 판별할 것인가? 자료구조. 알고리즘

class Room
{
	// Monster* unique_ptr<Monster>
private:
	vector<GameObject*> roomObjects;

	// roomObjects 안에 있는 데이터 중에서 몬스터 타입인 녀석들만 뽑아서 AvailableMonsters 재정렬을 하세요.

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

	// GameObject-> virtual void RoomEntryEvent(); // 몬스터방->전투, 보물상자->상자획득, 함정->함정,...
	void Battle(Player* player, BattleObject* other)    // Player Monster 싸우는 버전.. 확장성 있는 버전으로 만들었다.
	{
		// 턴
		while (true)
		{
			int playerIndex = 0;
			cout << "플레이어의 턴!" << endl;

			// --------------------- 턴마다 일어나야 하는 일 : 빈 마나 수정 1 -> 빈 마나 수정 최대 개수 만큼 채워준다.
			// 내가 먼저 공격
			cin >> playerIndex;  // 대기 하라.
			player->Attack(other);

			cout << "적의 턴!" << endl;
			// 니가 공격
			cout << "적의 턴 진행중..." << endl;
			Sleep(1000);
			other->Attack(player);
			cout << "모든 적의 턴 끝날때 대기중..." << endl;

			if(player->IsDeath() || other->IsDeath())
			{
				break;
			}
		}

		// 몬스터가 사망했을 때
		if (other->IsDeath())
		{
			// 몬스터를 처치했습니다

			// 보상을 얻었습니다.

			// 다음 플레이어의 행동을 처리하세요.....

			// 잠시 기다렸다가 나가세요.
			Sleep(1000);
		}
	}

public:	
	void PlayRoom(Player* player, Room room)
	{
		 int battleCount = room.RoomCount();

		 for (int i = 0; i < battleCount; i++)
		 {
			 // 전투

			 // 첫번째 방에 있는 오브젝트[몬스터]와 조우했다.

			 cout << i + 1 << "번째 방에 진입했습니다." << endl;

			 Monster* mon = room.Encount(i);

			 Battle(player, mon);

			 // 플레이어가 사망했으면?
			 if (player->IsDeath()) 
			 {
				 cout << i + 1 << "번째 방에서 플레이거 사망했습니다." << endl;
				 return;
			 }

			 system("cls");
		 }	

		 cout << "모든 방을 클리어 했습니다." << endl;
	}
};

// player.   battleManager

int main()
{
	cout << "16강 STL 예제 " << endl;

	Room room;
	vector<Monster*> copyMonsters;

	Monster* monsterB = new Monster(2, 600, 6, "B");
	monsterB->SetRoomType(RoomObjectType::BATTLE);

	copyMonsters.push_back(monsterB);   // 66
	copyMonsters.push_back(new Monster(1,500, 5, "A"));   // 55
	copyMonsters.push_back(new Monster(4,800, 8, "D"));   // 88
	copyMonsters.push_back(new Monster(3,700, 7, "C"));   // 77

	room.Initialize(copyMonsters);
	room.SetOrder();

	Player* player = new Player();
	// room에 있는 몬스터와 만났다.
	BattleManager _bm;
	_bm.PlayRoom(player, room);

}