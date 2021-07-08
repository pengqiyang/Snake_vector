#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "wall.h"
#include <vector>
using namespace std;


class Food {
public:
	Food(Wall& temp);
	int foodX, foodY;
	//…Ë÷√ ≥ŒÔ
	Wall& wall;

	void setFood();
};

#endif
