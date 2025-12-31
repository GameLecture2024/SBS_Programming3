#pragma once

#include <iostream>
#include <vector>
#include <memory>

class Player;
class Skill;

using namespace std;

// 1) unique, [shared, weak] 
// 2) shared : 다른 포인터가 플레이어가 소유한 스킬을 가리키고 있다.

// Command Pattern 패턴 사용하기
// 데이터를 저장하는 객체 선언. <- 자료구조
class Player
{
private:
	// map으로 만들어줘
	vector<unique_ptr<Skill>> skills;    //   Skill*

	//shared_ptr<Skill> skill;  // player 소유한 skill변수는 오로지 플레이어 객체만 가리키겠다.
public:
	void update();

	void setSkill(unique_ptr<Skill> skill);

	void useSkill(int index);
};

class Skill	 // 다형성을 사용해서 여러 스킬로 표현해보자.
{
	// 패시브 스킬, 엑티브 스킬
private:
	virtual bool IsAvailable() = 0;

public:

	virtual void Execute() = 0;
};

class Passive_Skill : public Skill
{
private:
	virtual bool IsAvailable() override;

public:
	virtual void Execute() override;
};

class Garen_Passive : public Passive_Skill
{
public:
	virtual void Execute() override;
};

class Active_Skill : public Skill
{
protected:
	int coolTime;
	int timeTick;
	int coolCheck;

	virtual bool IsAvailable() override;
public:

	virtual void Execute() override;
};


class Garen_Q : public Active_Skill	       // 온힛 계열 스킬
{

	virtual bool IsAvailable() override;

public:
	virtual void Execute() override;
};

class Garen_W : public Active_Skill	   	   // 자기 강화형 스킬
{

	virtual bool IsAvailable() override;

public:
	virtual void Execute() override;
};

class Garen_E : public Active_Skill
{

	virtual bool IsAvailable() override;

public:
	virtual void Execute() override;
};

class Garen_R : public Active_Skill
{

	virtual bool IsAvailable() override;

public:
	virtual void Execute() override;
};
