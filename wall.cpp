
//wall.cpp
#include "wall.h"
#include <vector>
void Wall::initWall()
{
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			//�i�֧Ԩo�d��
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
				gameArray[i][j] = '*';
			}else
				gameArray[i][j] = ' ';
		}
	}
}

void Wall::draw()
{
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cout << gameArray[i][j] << " ";
		}
		if (i == 5)
			cout << "created by qiyang";
		else if (i == 6)
			cout << "a: left";
		else if (i == 7)
			cout << "d: right";
		else if (i == 8)
			cout << "w: up";
		else if (i == 9)
			cout << "s: down";
		cout << endl;
	}
}

void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}

