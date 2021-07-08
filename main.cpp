//main.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include "wall.h"
#include "snake.h"
#include "food.h"

using namespace std;

void  gotoxy(HANDLE hOut , int x, int y)
{

	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);

}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量

int main() {
	srand((unsigned int)time(NULL));
	//是否死亡标识
	bool isDead = false;
	//上一次的方向
	char preKey = '\0';
	Wall wall;
	Food food(wall);

	Snake snake(wall,food);
	wall.initWall();
	wall.draw();
	food.setFood();
	snake.initSnake();


	gotoxy(hOut, 0, Wall::ROW);
	cout<<"得分"<<snake.getScore()<<endl;

	//接收用户输入
	while (!isDead)
	{
		char key = _getch();
		//判断如果是第一次按左键，则不能激活游戏
		//判断上一次移动方向
		if ('\0' == preKey && key == snake.LEFT)
			continue;

		do {
			//只允许上下左右键
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) {
				//判断本次的按键是否与上次冲突，比如移动方向为右，当按A时应该使本次失效
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP)) {
					key = preKey;//错误按键处理一次*********************************
				}
				else
					preKey = key;//不是冲突按键，直接更新

				preKey = key;
				if (true == snake.move(key)) {
					//移动成功
					//system("cls");
					//wall.draw();
					//Sleep(100);
			        gotoxy(hOut, 0 , Wall::ROW);

					cout<<"得分"<<snake.getScore()<<endl;
					Sleep(snake.getSleepTime());
				}
				else {
					isDead = true;
					gotoxy(hOut, 0 , Wall::ROW);
					cout<<"得分"<<snake.getScore()<<" game over"<<endl;
					//cout<<"得分"<<snake.getScore()<<endl;
					break;
				}
			}
			else {
				key = preKey;//强制将错误按键变为上一次移动方向，错误按键处理二次*******************************
			}
		} while (!_kbhit());//当没有键盘输入的时候，返回0
	}
	system("pause");
	return 1;
}

