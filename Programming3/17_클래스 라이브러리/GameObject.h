#pragma once

enum class RoomObjectType
{
	BATTLE = 0, TREASURE, REST
};

class GameObject
{
protected:
	int _id;
	RoomObjectType r_TYPE;
	// int instanceId;

public:
	GameObject(int id);		  // 숫자 -> casting Enum

	void SetRoomType(RoomObjectType r) { r_TYPE = r; }   // Set함수. BattleObject 생성되는 위치에서..하나씩 타입을 지정을 해줘야 한다.
};

class BattleObject : public GameObject
{
protected:
	int _hp;
	int _atk;
public:
	BattleObject(int id, int hp, int atk); 
	
	void Damage(int amount);
	bool IsDeath(); 

	virtual void Attack(BattleObject* other) = 0;
 
};

// 엑셀 시트
// 몬스터 (전투) + (드랍) + (스킬) 
// 고블린 클래스. 고유한 몬스터?
// 고블린 3마리랑 전투.  (A) = 1 B = 2 C = 3...
// 아이템. 집행검  A()    B 
