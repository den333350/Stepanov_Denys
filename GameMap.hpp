#include <vector>
#include "Constant.hpp"
#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

class GameMap {
public:
	int Col = ReturnCol();;
	int Row;
	int Total;
	char Wall;
	char ReturnMapSymbol(std::vector<int> v);
	char ReturnMapSymbol(int x, int y);
	void EditMapSymbol(std::vector<int> v, char c);
	void EditMapSymbol(int x, int y, char c);
	void CopyMap();
	void ReturnWall();
	
	
	
	GameMap() {
		
		ReturnWall();
		CopyMap();
	}
private:
	std::vector<std::vector<char>>Map;
	int ReturnCol();
};

#endif