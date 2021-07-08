#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <Windows.h>
#include "wall.h"
#include "food.h"
using namespace std;
class Snake {
public:
	Snake(Wall& tempWall, Food& tempFood);
	enum {
		UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd',
	};
	/*
	struct Point {
		//数据域
		int x, y;
		//指针域
		Point* next;
	};
	*/
	vector<COORD> body;
    vector<COORD>::iterator iter;
	//Point* pHead;//头结点
	Wall& wall;//维护成员
	Food& food;
	bool isRool;//判断循环标识
	//初始化
	void initSnake();
	//销毁节点
	void destroyPoint();
	//添加节点
	void addPoint(int x, int y);
	//删除节点
	void delPoint();
	//移动蛇，返回值代表移动是否成功
	bool move(char key);
	//设定难度
	//获取刷屏时间
	int getSleepTime();
	//获取蛇身段
	int countList();
	//返回分数
	int getScore();

};

#endif
