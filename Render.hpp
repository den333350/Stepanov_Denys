#include <iostream>
#include <conio.h>
#include<Windows.h>
#include "GameMap.hpp"
#ifndef RENDER_HPP
#define RENDER_HPP



class Render {
public:
	bool inGame = false;
	bool exitConsole = false;
	Render() {
		GetHandle();
		InitializeRender();
		Menu();
	}
	HANDLE Handle;
	
	void GetHandle();
	void gotoxy(int x, int y);
	void InitializeRender();
	void drawLevel(GameMap &map, int px, int py);
	void Menu();
};
#endif 