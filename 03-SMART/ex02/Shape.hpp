#pragma once

#include <cmath>
#include <iostream>

using namespace std;

int		sqr(int x){
	return (x * x);
}

double	findDist(int x1, int y1, int x2, int y2){
	return (sqrt(sqr(y2 - y1) + sqr(x2 - x1)));
}

class Shape{
public:
	Shape(void);
	virtual ~Shape();

	virtual double	getArea(void) = 0;
	virtual double	getPerimeter(void) = 0;
};

Shape::Shape(void){
}

Shape::~Shape(){
}
