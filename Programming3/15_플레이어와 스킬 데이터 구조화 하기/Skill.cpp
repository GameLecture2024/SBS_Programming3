#include "Skill.h"
#include "Windows.h"
#include "conio.h"

bool Passive_Skill::IsAvailable()
{
    // Update 구조.    TimeTick   4씩. 4초마다 실행되는 패시브다.

    return true;
}

void Passive_Skill::Execute()
{
    if (IsAvailable())
    {
        // 로직을 실행하라.

    }
}

bool Active_Skill::IsAvailable()
{
    // 플레이어가 입력을 했을 때.
    // 쿨타임이 아닐 때

    return false;
}

void Active_Skill::Execute()
{
    if (IsAvailable())
    {

    }
}

void Garen_Passive::Execute()
{
    cout << "가렌이 8초 동안 피해를 입지 않거나 적의 스킬에 맞지 않으면 5초마다 최대 체력의 일정 비율롤아이콘-레벨만큼 회복합니다. \n" << endl;
}

bool Garen_Q::IsAvailable()
{
    timeTick++;
    if (timeTick >= coolCheck)
    {
        timeTick = 0;
        return true;
    }

    return false;
}

void Garen_Q::Execute()
{
    if (IsAvailable())
    {
         cout << "가렌에게 적용된 모든 둔화 효과가 제거되고 일정 시간 동안 이동 속도가 35% 상승합니다."
              << "다음 기본 공격은 1.5초 동안 롤아이콘 - 군중제어 침묵 침묵시키고 추가 물리 피해를 입힙니다. \n" << endl;

         coolCheck = coolTime;
    }
}

void Player::update()
{
    if (_kbhit()) {
        // 2. 입력된 키 읽기
        char key = _getch();

        // 3. 입력값에 따른 반환 처리
        switch (key) 
        {
            case 'q': case 'Q': useSkill(0); break;
            case 'w': case 'W': useSkill(1); break;
            case 'e': case 'E': useSkill(2); break;
            case 'r': case 'R': useSkill(3); break;
            default: ; // q,w,e,r 이외의 키가 눌린 경우
        }
    }
}

// 스킬을 습득.
void Player::setSkill(unique_ptr<Skill> skill)
{
    skills.push_back(std::move(skill));   // copy
}

void Player::useSkill(int index)
{
    // skills["q"]->Execute();
    // skills['w']
    skills[index]->Execute();
}
