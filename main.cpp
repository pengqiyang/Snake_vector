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
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������

int main() {
	srand((unsigned int)time(NULL));
	//�Ƿ�������ʶ
	bool isDead = false;
	//��һ�εķ���
	char preKey = '\0';
	Wall wall;
	Food food(wall);

	Snake snake(wall,food);
	wall.initWall();
	wall.draw();
	food.setFood();
	snake.initSnake();


	gotoxy(hOut, 0, Wall::ROW);
	cout<<"�÷�"<<snake.getScore()<<endl;

	//�����û�����
	while (!isDead)
	{
		char key = _getch();
		//�ж�����ǵ�һ�ΰ���������ܼ�����Ϸ
		//�ж���һ���ƶ�����
		if ('\0' == preKey && key == snake.LEFT)
			continue;

		do {
			//ֻ�����������Ҽ�
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) {
				//�жϱ��εİ����Ƿ����ϴγ�ͻ�������ƶ�����Ϊ�ң�����AʱӦ��ʹ����ʧЧ
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP)) {
					key = preKey;//���󰴼�����һ��*********************************
				}
				else
					preKey = key;//���ǳ�ͻ������ֱ�Ӹ���

				preKey = key;
				if (true == snake.move(key)) {
					//�ƶ��ɹ�
					//system("cls");
					//wall.draw();
					//Sleep(100);
			        gotoxy(hOut, 0 , Wall::ROW);

					cout<<"�÷�"<<snake.getScore()<<endl;
					Sleep(snake.getSleepTime());
				}
				else {
					isDead = true;
					gotoxy(hOut, 0 , Wall::ROW);
					cout<<"�÷�"<<snake.getScore()<<" game over"<<endl;
					//cout<<"�÷�"<<snake.getScore()<<endl;
					break;
				}
			}
			else {
				key = preKey;//ǿ�ƽ����󰴼���Ϊ��һ���ƶ����򣬴��󰴼��������*******************************
			}
		} while (!_kbhit());//��û�м��������ʱ�򣬷���0
	}
	system("pause");
	return 1;
}

