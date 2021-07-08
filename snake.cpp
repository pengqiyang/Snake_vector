#include "snake.h"
#include "wall.h"
#include <Windows.h>
#include <vector>

void  gotoxy1(HANDLE hOut1 , int x, int y)
{

	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut1, pos);

}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
//保证拿到main函数中的同一个wall
Snake::Snake(Wall& tempWall, Food& tempFood):wall(tempWall), food(tempFood)
{

	isRool = false;
}

void Snake::initSnake()
{
    body.clear();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);

}



void Snake::addPoint(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;


	//如果原来的头不为空，则改为身子
	if (body.size() > 0) {

		wall.setWall(body.back().X, body.back().Y, '=');
		gotoxy1(hOut1,  body.back().Y * 2 , body.back().X);
		cout<<"=";
	}

    body.push_back(Pos);

	wall.setWall(body.back().X, body.back().Y, '@');
	gotoxy1(hOut1, body.back().Y * 2 , body.back().X);
    cout<<"@";



}

//需要借助双指针法，一个指向待删除的节点，一个指向待删除前个节点
void Snake::delPoint()
{
	//两个节点以上才删除
	if (body.size()==1) {
		return;
	}

	//此时已经移动到尾节点，删除
	wall.setWall(body.front().X, body.front().Y, ' ');
    gotoxy1(hOut1, body.front().Y * 2 , body.front().X);
    cout<<" ";
	body.erase(body.begin());
}

bool Snake::move(char key)
{

	int x = body.back().X;
	int y = body.back().Y;

	switch (key) {
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}
    if (wall.getWall(x, y) == '*')
    {

        int ss = 0;
    }
	//判断如果下一步碰到的是尾巴，不应该死亡
	//此时已经移动到尾节点，删除
	if (body.front().X == x && body.front().Y == y) {
		//碰到尾巴，循环
		isRool = true;
	}
	else {
		//判断用户到达位置是否成功
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
			addPoint(x, y);//多走一步
			delPoint();
			//system("cls");//这一步的作用？
			//wall.draw();
    		gotoxy1(hOut1, 0 , Wall::ROW);
			cout << "game over" << endl;
			return false;
		}
	}

	//下一位置有效，可以变换
	//移动成功分两种，吃到食物和没迟到食物
	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		//重新设置食物
		food.setFood();
	}
	else {
		//未吃到食物
		addPoint(x, y);
		delPoint();
		if (isRool == true) {
			wall.setWall(x, y, '@');
		    gotoxy1(hOut1, y * 2 , x);
    		cout<<"@";
		}
	}
	return true;
}
int Snake::getSleepTime()
{

	int sleepTime=0;
    int size = countList();
    if(size<5)
    {
    	sleepTime = 300;
	}
	else if(size>=6 && size<=8)
	{
		sleepTime = 200;
	}
	else{
		sleepTime = 100;
	}

	return sleepTime;
}

int Snake::countList()
{

	return body.size();
}
int Snake::getScore()
{
	int size = countList();
	int score = (size-3)*100;
	return score;
}

