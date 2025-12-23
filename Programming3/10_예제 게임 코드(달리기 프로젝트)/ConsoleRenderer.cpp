#include "ConsoleRenderer.h"
#include <iostream>

ConsoleRenderer::ConsoleRenderer(int width, int height)
    : m_nScreenIndex(0), m_width(width), m_height(height) {

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE; // 화면 깜빡임 방지를 위해 커서를 숨깁니다.

    for (int i = 0; i < 2; ++i) {
        m_hScreen[i] = CreateConsoleScreenBuffer(
            GENERIC_READ | GENERIC_WRITE,
            0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
        );
        SetConsoleCursorInfo(m_hScreen[i], &cci);
    }
}

ConsoleRenderer::~ConsoleRenderer() {
    CloseHandle(m_hScreen[0]);
    CloseHandle(m_hScreen[1]);
}

void ConsoleRenderer::Clear() {
    COORD coor = { 0, 0 };
    DWORD dw;
    // 설정된 너비와 높이만큼 화면을 공백으로 채웁니다.
    FillConsoleOutputCharacter(m_hScreen[m_nScreenIndex], ' ', m_width * m_height, coor, &dw);
}

void ConsoleRenderer::Flipping() {
    SetConsoleActiveScreenBuffer(m_hScreen[m_nScreenIndex]);
    m_nScreenIndex = !m_nScreenIndex;
}

void ConsoleRenderer::Print(int x, int y, const std::string& str) {
    DWORD dw;
    COORD cursorPosition = { static_cast<SHORT>(x), static_cast<SHORT>(y) };

    SetConsoleCursorPosition(m_hScreen[m_nScreenIndex], cursorPosition);
    WriteFile(m_hScreen[m_nScreenIndex], str.c_str(), static_cast<DWORD>(str.length()), &dw, NULL);
}

