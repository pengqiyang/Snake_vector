#ifndef WALL_H
#define WALL_H
#include <iostream>
#include <vector>
using namespace std;

class Wall {
public:
	enum {
		ROW = 26,
		COL = 26,
	};
	//初始化墙壁
	void initWall();
	//展示墙壁
	void draw();
	//根据索引设置二维数组里的内容
	void setWall(int x, int y, char c);
	//根据索引获取当前位置的符号
	char getWall(int x, int y);

private:
	char gameArray[ROW][COL];
};

#endif
