#pragma once
#include "GameMap.hpp"

namespace RenderConstants {

    const int screenColumns = 28;
    const int screenRows = 36;
    
    const int ScreenWidth=12;
    const int ScreenHeight=16;
}

HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y+3;
    SetConsoleCursorPosition(Handle, coord);
}

void InitializeRender() {
    COORD crd = { RenderConstants::screenColumns, RenderConstants::screenRows };
    SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
    SetConsoleWindowInfo(Handle, true, &src);
    SetConsoleScreenBufferSize(Handle, crd);

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(Handle, &cursorInfo);


    CONSOLE_FONT_INFOEX font = {};
    GetCurrentConsoleFontEx(Handle, false, &font);
    font.dwFontSize = { RenderConstants::ScreenWidth, RenderConstants::ScreenHeight };
    font.cbSize = sizeof(font);
    lstrcpyW(font.FaceName, L"Terminal");
    SetCurrentConsoleFontEx(Handle, false, &font);
}

void drawLevel() {
    for (int counter = 0; counter <= GameConst::Total; ++counter) {
        int x, y;
        x = counter % GameConst::gameCol;
        y = counter % GameConst::gameRow;

            gotoxy(x, y );
            if (NewMap[y][x] == GameConst::WALL) {
                SetConsoleTextAttribute(Handle, 19);
                std::cout << NewMap[y][x];
            }
            if (NewMap[y][x] == '.'|| NewMap[y][x] == '+') {
                SetConsoleTextAttribute(Handle, 12);
                std::cout << NewMap[y][x];
            }
    }
}