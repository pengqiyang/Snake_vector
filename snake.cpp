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
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
//��֤�õ�main�����е�ͬһ��wall
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


	//���ԭ����ͷ��Ϊ�գ����Ϊ����
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

//��Ҫ����˫ָ�뷨��һ��ָ���ɾ���Ľڵ㣬һ��ָ���ɾ��ǰ���ڵ�
void Snake::delPoint()
{
	//�����ڵ����ϲ�ɾ��
	if (body.size()==1) {
		return;
	}

	//��ʱ�Ѿ��ƶ���β�ڵ㣬ɾ��
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
	//�ж������һ����������β�ͣ���Ӧ������
	//��ʱ�Ѿ��ƶ���β�ڵ㣬ɾ��
	if (body.front().X == x && body.front().Y == y) {
		//����β�ͣ�ѭ��
		isRool = true;
	}
	else {
		//�ж��û�����λ���Ƿ�ɹ�
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
			addPoint(x, y);//����һ��
			delPoint();
			//system("cls");//��һ�������ã�
			//wall.draw();
    		gotoxy1(hOut1, 0 , Wall::ROW);
			cout << "game over" << endl;
			return false;
		}
	}

	//��һλ����Ч�����Ա任
	//�ƶ��ɹ������֣��Ե�ʳ���û�ٵ�ʳ��
	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		//��������ʳ��
		food.setFood();
	}
	else {
		//δ�Ե�ʳ��
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

