#include "Render.hpp"


void Render::GetHandle() {
    Handle = GetStdHandle(STD_OUTPUT_HANDLE);;
}

void Render::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y + 3;
    SetConsoleCursorPosition(Handle, coord);
}

void Render::InitializeRender() {
    COORD crd = { RENDER_CONSTANTS::SCREEN_COLUMS, RENDER_CONSTANTS::SCREEN_ROWS };
    SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
    SetConsoleWindowInfo(Handle, true, &src);
    SetConsoleScreenBufferSize(Handle, crd);

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(Handle, &cursorInfo);


    CONSOLE_FONT_INFOEX font = {24,32};
    GetCurrentConsoleFontEx(Handle, false, &font);
    font.dwFontSize = { RENDER_CONSTANTS::TEXT_WIDTH, RENDER_CONSTANTS::TEXT_HEIGHT };
    font.cbSize = sizeof(font);
    lstrcpyW(font.FaceName, L"Terminal");
    SetCurrentConsoleFontEx(Handle, false, &font);
}

void Render::drawLevel(GameMap &map, int px, int py) {
    map.EditMapSymbol(px,py, ' ');
    for (int counter = 0; counter <= map.Total; ++counter) {
        int x, y;
        x = counter % map.Col;
        y = counter % map.Row;

        gotoxy(x, y);
        if (map.ReturnMapSymbol(x,y)==map.Wall) {
            SetConsoleTextAttribute(Handle, 15);
            std::cout << map.ReturnMapSymbol(x,y);
        }
        if (map.ReturnMapSymbol(x, y) == '.' || map.ReturnMapSymbol(x, y) == 'o') {
            SetConsoleTextAttribute(Handle, 12);
            std::cout << map.ReturnMapSymbol(x, y);
        }
    }
}

void Render::Menu() {
    char c = '0';
    int chosen = 0;
    system("cls");

    while ((inGame == false))
    {
        SetConsoleTextAttribute(Handle, 11);
        gotoxy(13, 9);
        std::cout << char(24);
        gotoxy(13, 10);
        std::cout << "W";

        gotoxy(13, 22);
        std::cout << char(25);
        gotoxy(13, 21);
        std::cout << "S";

        SetConsoleTextAttribute(Handle, 15);
        gotoxy(10, 14);
        std::cout << "NEW GAME";
        gotoxy(12, 17);
        std::cout << "EXIT";

        while (c != char(13))
        {
            SetConsoleTextAttribute(Handle, 10);
            gotoxy(7, 14 + chosen);
            std::cout << "->";
            gotoxy(19, 14 + chosen);
            std::cout << "<-";
            gotoxy(0, 0);
            c = _getch();
            gotoxy(7, 14 + chosen);
            std::cout << "  ";
            gotoxy(19, 14 + chosen);
            std::cout << "  ";
            if (c == 's' || c == 'S' || c == '�' || c == '�')
            {
                if (chosen < 3)
                {
                    chosen += 3;
                }
            }
            if (c == 'w' || c == 'W' || c == '�' || c == '�')
            {
                if (chosen > 0)
                {
                    chosen -= 3;
                }
            }
        }
        if (chosen == 0)
        {
            inGame = true;

        }
        if (chosen == 3)
        {
            exitConsole = true;
            exit(0);
        }
        c = ' ';

        system("cls");
    }

}

