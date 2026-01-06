#include "Monster.h"
#include "Player.h"

#include <iostream>

using namespace std;

int main()
{
	Player* player = new Player();
	Monster* monsterA = new Monster(1, RoomObjectType::BATTLE, 100, 10, "A");
	Monster* monsterB = new Monster(2, static_cast<RoomObjectType>(0),200, 20, "B");
	Monster* monsterC = new Monster(3, static_cast<RoomObjectType>(0), 300, 30, "C");
	Monster* monsterD = new Monster(4, static_cast<RoomObjectType>(0), 400, 40, "D");

	player->Attack(monsterA);
	monsterA->Attack(player);
}