#include "GameMap.hpp"

namespace GAME_CONSTANTS {
	const int GAME_COL = 28;
	const int GAME_ROW = 31;
	const int TOTAL = GAME_COL * GAME_ROW;
	const char WALL = '#';
	const std::vector< std::vector<char>> MAIN_MAP = {
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','+','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','+','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','.','#'},
{'#','.','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','.','#'},
{'#','.','.','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','.','.','#'},
{'#','#','#','#','#','#','.','#','#','#','#','#',' ','#','#',' ','#','#','#','#','#','.','#','#','#','#','#','#'},
{'#','#','#','#','#','#','.','#','#','#','#','#',' ','#','#',' ','#','#','#','#','#','.','#','#','#','#','#','#'},
{'#','#','#','#','#','#','.','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','.','#','#','#','#','#','#'},
{'#','#','#','#','#','#','.','#','#',' ','#','#','#',' ',' ','#','#','#',' ','#','#','.','#','#','#','#','#','#'},
{'#','#','#','#','#','#','.','#','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#','#','.','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ',' ','.',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','.',' ',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#','.','#','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#','#','.','#','#','#','#','#','#'},
{'#','#','#','#','#','#','.','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','.','#','#','#','#','#','#'},
{'#','#','#','#','#','#','.','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','.','#','#','#','#','#','#'},
{'#','#','#','#','#','#','.','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','.','#','#','#','#','#','#'},
{'#','#','#','#','#','#','.','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','.','#','#','#','#','#','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','+','.','.','#','#','.','.','.','.','.','.','.',' ',' ','.','.','.','.','.','.','.','#','#','.','.','+','#'},
{'#','#','#','.','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','.','#','#','#'},
{'#','#','#','.','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','.','#','#','#'},
{'#','.','.','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','#','#','.','#'},
{'#','.','#','#','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','#','#','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
	};
}

void GameMap::CopyMap() {
	Map = GAME_CONSTANTS::MAIN_MAP;
}

void GameMap::ReturnWall() {
	Row = GAME_CONSTANTS::GAME_ROW;
	Total = GAME_CONSTANTS::TOTAL;
	Wall = GAME_CONSTANTS::WALL;
}

char GameMap::ReturnMapSymbol(int x, int y) {
	return Map[y][x];
}
void GameMap::EditMapSymbol(int x, int y, char c) {
	Map[y][x] = c;
}
int GameMap::ReturnCol() {
	return GAME_CONSTANTS::GAME_COL;
}