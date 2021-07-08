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
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
Food::Food(Wall& tempWall):wall(tempWall)
{

}

void Food::setFood()
{
	while (true) {
		foodX = rand() % (Wall::ROW - 2) + 1;//保证随机生成的点处于1-12的单元格内
		foodY = rand() % (Wall::COL - 2) + 1;
		//如果随机的位置是蛇头或蛇神 就重新生成
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

