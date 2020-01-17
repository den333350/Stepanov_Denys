#pragma once
#include <iostream>
#include <conio.h>
#include<Windows.h>
#include "GameMap.hpp"

class Render:public GameMap {
public:
	bool inGame = false;
	bool exitConsole = false;
	Render() {
		GetHandle();
		InitializeRender();
	}
	HANDLE Handle;
	
	void GetHandle();
	void gotoxy(int x, int y);
	void InitializeRender();
	void drawLevel(int PlayerCordX, int PlayerCordY);
	void Menu();
};