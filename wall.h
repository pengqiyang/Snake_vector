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
	//��ʼ��ǽ��
	void initWall();
	//չʾǽ��
	void draw();
	//�����������ö�ά�����������
	void setWall(int x, int y, char c);
	//����������ȡ��ǰλ�õķ���
	char getWall(int x, int y);

private:
	char gameArray[ROW][COL];
};

#endif
