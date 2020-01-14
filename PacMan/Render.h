#pragma once
#include "GameMap.h"

static const int screenColumns = 28;
static const int screenRows = 36;


HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(Handle, coord);
}

void InitializeRender() {
    COORD crd = { screenColumns, screenRows };
    SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
    SetConsoleWindowInfo(Handle, true, &src);
    SetConsoleScreenBufferSize(Handle, crd);

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(Handle, &cursorInfo);


    CONSOLE_FONT_INFOEX font = {};
    GetCurrentConsoleFontEx(Handle, false, &font);
    font.dwFontSize = { 12, 16 };
    font.cbSize = sizeof(font);
    lstrcpyW(font.FaceName, L"Terminal");
    SetCurrentConsoleFontEx(Handle, false, &font);
}

void drawLevel() {
    for (int x = 1; x <= gameCol; x++) {
        for (int y = 1; y < gameRow; y++) {
            gotoxy(x, y + 3);
            if (Newmap[y - 1][x - 1] == 1) {
                SetConsoleTextAttribute(Handle, 17);

                std::cout << '#';
            }
            if (Newmap[y - 1][x - 1] == 0) {
                SetConsoleTextAttribute(Handle, 15);

                std::cout << '.';
            }
            if (Newmap[y - 1][x - 1] == 3) {
                SetConsoleTextAttribute(Handle, 15);

                std::cout << '+';
            }
        }
    }
}