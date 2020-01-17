#pragma once

#include <vector>

class GameMap {
public:
	int Col = ReturnCol();
	int Row;
	int Total;
	char Wall;
	char ReturnMapSymbol(int x, int y);
	void EditMapSymbol(int x, int y, char c);
	void CopyMap();
	void ReturnWall();
	
	int ReturnCol();

	GameMap() {
		
		ReturnWall();
		CopyMap();
	}
private:
	std::vector< std::vector<char>>Map;
};