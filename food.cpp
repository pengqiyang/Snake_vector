//food.cpp
#include "food.h"
#include <Windows.h>
#include "wall.h"
#include <vector>
void  gotoxy2(HANDLE hOut1 , int x, int y)
{

	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut1, pos);

}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
Food::Food(Wall& tempWall):wall(tempWall)
{

}

void Food::setFood()
{
	while (true) {
		foodX = rand() % (Wall::ROW - 2) + 1;//��֤������ɵĵ㴦��1-12�ĵ�Ԫ����
		foodY = rand() % (Wall::COL - 2) + 1;
		//��������λ������ͷ������ ����������
		if (wall.getWall(foodX, foodY) == ' ') {
			wall.setWall(foodX, foodY, '#');

		    gotoxy2(hOut2, 2*foodY , foodX);
		    cout<<'#';
			//cout << "game over" << endl;
			break;
		}
	}
	return ;
}

