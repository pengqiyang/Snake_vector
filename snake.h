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
		//������
		int x, y;
		//ָ����
		Point* next;
	};
	*/
	vector<COORD> body;
    vector<COORD>::iterator iter;
	//Point* pHead;//ͷ���
	Wall& wall;//ά����Ա
	Food& food;
	bool isRool;//�ж�ѭ����ʶ
	//��ʼ��
	void initSnake();
	//���ٽڵ�
	void destroyPoint();
	//��ӽڵ�
	void addPoint(int x, int y);
	//ɾ���ڵ�
	void delPoint();
	//�ƶ��ߣ�����ֵ�����ƶ��Ƿ�ɹ�
	bool move(char key);
	//�趨�Ѷ�
	//��ȡˢ��ʱ��
	int getSleepTime();
	//��ȡ�����
	int countList();
	//���ط���
	int getScore();

};

#endif
