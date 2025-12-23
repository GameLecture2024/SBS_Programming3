#pragma once
#include <Windows.h>
#include <string>

class ConsoleRenderer {
private:
    HANDLE m_hScreen[2];
    int m_nScreenIndex;
    int m_width;
    int m_height;

public:
    ConsoleRenderer(int width = 160, int height = 50);
    ~ConsoleRenderer();

    void Clear();
    void Flipping();
    void Print(int x, int y, const std::string& str);

    // 복사 방지 (핸들 관리 클래스의 안전성을 위함)
    ConsoleRenderer(const ConsoleRenderer&) = delete;
    ConsoleRenderer& operator=(const ConsoleRenderer&) = delete;
};


