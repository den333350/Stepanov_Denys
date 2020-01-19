#include "GameMap.hpp"



void GameMap::CopyMap() {
	Map = GAME_CONSTANTS::MAIN_MAP;
}

void GameMap::ReturnWall() {
	Row = GAME_CONSTANTS::GAME_ROW;
	Total = GAME_CONSTANTS::TOTAL;
	Wall = GAME_CONSTANTS::WALL;
}

char GameMap::ReturnMapSymbol(std::vector<int> v) {
	return Map[v[0]][v[1]];
}

char GameMap::ReturnMapSymbol(int x, int y) {
	return Map[y][x];
}

void GameMap::EditMapSymbol(std::vector<int> v, char c) {
	Map[v[0]][v[1]] = c;
}

void GameMap::EditMapSymbol(int x, int y, char c) {
	Map[y][x] = c;
}

int GameMap::ReturnCol() {
	return GAME_CONSTANTS::GAME_COL;
}